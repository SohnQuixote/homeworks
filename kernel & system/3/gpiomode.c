#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/version.h>

#define DEVICE_NAME "gpiomode"

static int ccount = 0;
static DECLARE_WAIT_QUEUE_HEAD(wq);
static int flag = 0;
static int MYDRV_MAJOR;
static char gpiomode_data[1];
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


static struct gpio leds[] ={
	{23 , GPIOF_OUT_INIT_LOW , "LED 1"},
};
static struct gpio buttons[] = {
	{25 , GPIOF_IN , "BUTTON 1"},
};
static int button_irqs[] = {-1};

static irqreturn_t button_isr(int irq,  void *data)
{
	printk(KERN_DEBUG "process %i (%s) awakening the readers...\n" , current->pid , current ->comm);
	flag = 1;
	wake_up_interruptible(&wq);
	ccount -=1;
	if(ccount ==0){
		gpio_set_value(leds[0].gpio , 0);
	}
	return IRQ_HANDLED;
}
static ssize_t mydrv_read(struct file *file, char *buf, size_t count, loff_t *ppos)
{
	gpio_set_value(leds[0].gpio , 1);
	printk(KERN_DEBUG "process %i (%s) going to sleep\n" , current->pid , current->comm);
	ccount+=1;
	wait_event_interruptible(wq , flag!=0);
	flag = 0;
	gpiomode_data[0] = ccount;
	if (copy_to_user(buf , gpiomode_data, count))
		return -EFAULT;
	printk(KERN_DEBUG "awoken %i (%s)\n" , current->pid , current->comm);
	
	return 0;


}
struct file_operations mydrv_fops = {
	.owner = THIS_MODULE,
	.read = mydrv_read,
	.compat_ioctl = mydrv_ioctl,
	.open = mydrv_open,
	.release = mydrv_release,
};
static int __init gpiomode_init(void)
{
	int ret = 0 ;
	if ((MYDRV_MAJOR = register_chrdev(0, DEVICE_NAME,
	&mydrv_fops)) < 0){
		printk(KERN_INFO "can't be registered \n");
		return MYDRV_MAJOR;
	}
	printk(KERN_INFO "major NO = %d \n", MYDRV_MAJOR);	
	
	ret = gpio_request_array(leds , ARRAY_SIZE(leds));
	if(ret){
		return ret;
	}
	ret = gpio_request_array(buttons , ARRAY_SIZE(buttons));
	if(ret){
		goto fail1;
	}
	ret = gpio_to_irq(buttons[0].gpio);
	if(ret < 0){
		goto fail2;
	}
	button_irqs[0] = ret;
	ret = request_irq(button_irqs[0] , button_isr , IRQF_TRIGGER_RISING , "gpiomod#button1" , NULL);
	if(ret) {
		goto fail2;
	}

	
	return 0;
	
	fail2:
		gpio_free_array(buttons , ARRAY_SIZE(buttons));
	fail1:
		gpio_free_array(leds,  ARRAY_SIZE(leds));
		return ret;
}

static void __exit gpiomode_exit(void)
{
	int i;
	
	for(i = 0 ; i<ARRAY_SIZE(buttons) ; i++){
		free_irq(button_irqs[i] , NULL);
	}
	for (i =0;i<ARRAY_SIZE(leds);i++){
		gpio_set_value(leds[i].gpio , 0);
	}
	gpio_free_array(leds, ARRAY_SIZE(leds));
	gpio_free_array(buttons , ARRAY_SIZE(buttons));
	
}

module_init(gpiomode_init);
module_exit(gpiomode_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SOHN");
MODULE_DESCRIPTION("nice");
MODULE_INFO(intree , "Y");
