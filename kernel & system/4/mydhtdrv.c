#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>
#include <linux/version.h>
#include <linux/workqueue.h>
#include <linux/delay.h>


#define DEVICE_NAME "mydhtdrv"
#define GPIO 4
#define GPIO2 23
#define MAXTIMINGS 83
#define MAXLENGTH 5


static void handler_pre(struct work_struct *w);
static void handler(struct work_struct *w);
static struct workqueue_struct *wq = 0;
static DECLARE_DELAYED_WORK(mywork_pre , handler_pre);
static DECLARE_DELAYED_WORK(mywork , handler);
static char * mydht_data;
static int * dht11_dat;
static int MYDRV_MAJOR;
static unsigned long twosec;
static unsigned long eighteen;
static int FLAG = 0;
static void handler_pre(struct work_struct *w)
{
	gpio_set_value(GPIO2,1);
	memset(dht11_dat, 0, sizeof(int) * 5);
	gpio_set_value(GPIO,0);
	eighteen = msecs_to_jiffies(18);
	if(!wq)
		wq = create_singlethread_workqueue("handler");
	if(wq)
		queue_delayed_work(wq,&mywork,eighteen);
	
}
static void handler(struct work_struct *w)
{
	uint8_t counter = 0;
	uint8_t laststate = 1;
	uint8_t j=0,i;
	uint8_t state = 0;
	gpio_set_value(GPIO,1);
	udelay(30);
	for (i = 0; i < MAXTIMINGS; i++) {
		counter = 0;
	while (gpio_get_value(GPIO) == laststate) {
		counter++;
		udelay(1);
		if (counter == 200) break;
	}
	laststate = gpio_get_value(GPIO);
	if (counter == 200) break;
	if ((i >= 4) && (i % 2 == 0)) 
	{
		dht11_dat[j / 8] <<= 1;
	if (counter > 40) 
		dht11_dat[j / 8] |= 1;
	j++;
	}
	} 
	if ((j >= 40) && (dht11_dat[4] == ((dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xff))) {
		FLAG = 1;
		mydht_data[0] = dht11_dat[0];
		mydht_data[1] = dht11_dat[1];
		mydht_data[2] = dht11_dat[2];
		mydht_data[3] = dht11_dat[3];
		mydht_data[4] = dht11_dat[4];
	} else
	{
	}
	gpio_set_value(GPIO2,0);
	queue_delayed_work(wq, &mywork_pre,twosec);
}
static int mydrv_open(struct inode *inode , struct file *file)
{
	if(MAJOR(inode ->i_rdev)!= MYDRV_MAJOR)
		return -1;
	return 0;
}
static int mydrv_release(struct inode *inode , struct file *file)
{
	if(MAJOR(inode ->i_rdev )!= MYDRV_MAJOR)
		return -1;
	return 0;
}
static long mydrv_ioctl(struct file *file , unsigned int cmd , unsigned long arg)
{
	printk(KERN_INFO , "mydrv_ioctl invoked!!\n");
	return 0;
}
static ssize_t mydrv_read(struct file *file, char *buf, size_t count, loff_t *ppos)
{
	if(FLAG ==1){
	if (copy_to_user(buf, mydht_data, count))
		return -EFAULT;
		//FLAG = 0;
	}
	if(FLAG == 0){
		return -EFAULT;
	}
	return count;
}
struct file_operations mydrv_fops = {
	.owner = THIS_MODULE,
	.read = mydrv_read,
	.compat_ioctl = mydrv_ioctl,
	.open = mydrv_open,
	.release = mydrv_release,
};
int __init mydrv_init(void)
{
	if ((MYDRV_MAJOR = register_chrdev(0, DEVICE_NAME,
	&mydrv_fops)) < 0){
		printk(KERN_INFO "can't be registered \n");
		return MYDRV_MAJOR;
	}
	printk(KERN_INFO "major NO = %d \n", MYDRV_MAJOR);
	if((mydht_data = (char *) kmalloc(MAXLENGTH * sizeof(char), GFP_KERNEL)) == NULL)
	{
		unregister_chrdev(MYDRV_MAJOR , DEVICE_NAME);
		return -ENOMEM;
	}
	if((dht11_dat = (int *) kmalloc(MAXLENGTH * sizeof(int), GFP_KERNEL)) == NULL)
	{
		unregister_chrdev(MYDRV_MAJOR , DEVICE_NAME);
		return -ENOMEM;
	}
	twosec = msecs_to_jiffies(2000);
	gpio_is_valid(GPIO);
	gpio_is_valid(GPIO2);
	gpio_direction_output(GPIO2,0);
	
	if(!wq)
		wq = create_singlethread_workqueue("handler");
	if(wq)
		queue_delayed_work(wq,&mywork_pre,twosec);

	return 0;
}
void __exit mydrv_cleanup(void)
{
	if(wq)
		destroy_workqueue(wq);
	unregister_chrdev(MYDRV_MAJOR, DEVICE_NAME);
	gpio_is_valid(GPIO2);
	gpio_direction_output(GPIO2,0);
}
module_init(mydrv_init);
module_exit(mydrv_cleanup);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SOHNQUIXOTE");
MODULE_DESCRIPTION("dht11");
MODULE_INFO(intree , "Y");
