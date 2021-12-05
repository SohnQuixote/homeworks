#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mydrv"
#define MYDRV_MAX_LENGTH 40
#define MIN(a,b) (((a)<(b)) ? (a) :(b))
static int MYDRV_MAJOR;
static char *mydrv_data;
static int mydrv_read_offset, mydrv_write_offset;
static int circle_invoked;
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
	int circle_count_one = 0;
	int circle_count_two = 0;
	if ((buf == NULL) || (count < 0))
		return -EINVAL;
	if (((mydrv_write_offset - mydrv_read_offset) <= 0) && (circle_invoked == 0))
	{
		return 0;
		//err
	}
	else if (((mydrv_write_offset - mydrv_read_offset) <= 0) && (circle_invoked == 1))
	{
		
		if((mydrv_read_offset + count) > MYDRV_MAX_LENGTH)
		{
			circle_count_one = MYDRV_MAX_LENGTH-mydrv_read_offset;
			circle_count_two = count - circle_count_one;
			if (copy_to_user(buf, mydrv_data + mydrv_read_offset, circle_count_one))
				return -EFAULT;
			if (copy_to_user(buf + circle_count_one, mydrv_data, circle_count_two))
				return -EFAULT;
			//circular buffer
		}
		else
		{
			if (copy_to_user(buf, mydrv_data + mydrv_read_offset, count))
				return -EFAULT;
		}
	}
		
	else
	{
		//count = MIN((mydrv_write_offset - mydrv_read_offset), count);
		if (copy_to_user(buf, mydrv_data + mydrv_read_offset, count))
			return -EFAULT;
		
	}
	mydrv_read_offset += count;
	mydrv_read_offset %= MYDRV_MAX_LENGTH;
	return count;
}
static ssize_t mydrv_write(struct file *file, const char *buf, size_t count, loff_t *ppos)
{
	int circle_count_one = 0;
	int circle_count_two = 0;
	if ((buf==NULL) || (count < 0))
		return -EINVAL;
	if (count + mydrv_write_offset > MYDRV_MAX_LENGTH){
		circle_count_one = MYDRV_MAX_LENGTH - mydrv_write_offset;
		circle_count_two = count - circle_count_one;
		if (copy_from_user(mydrv_data + mydrv_write_offset,buf, circle_count_one))
			return -EFAULT;
		if (copy_from_user(mydrv_data, buf+circle_count_one, circle_count_two))
			return -EFAULT;
		circle_invoked = 1;	
	}
	if (copy_from_user(mydrv_data + mydrv_write_offset, buf, count))
		return -EFAULT;
	mydrv_write_offset += count;
	mydrv_write_offset %= MYDRV_MAX_LENGTH;
	return count;
}
struct file_operations mydrv_fops = {
	.owner = THIS_MODULE,
	.read = mydrv_read,
	.write = mydrv_write,
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
	if ((mydrv_data = (char *)kmalloc(MYDRV_MAX_LENGTH *
	sizeof(char), GFP_KERNEL))==NULL){
		unregister_chrdev(MYDRV_MAJOR, DEVICE_NAME);
		return -ENOMEM;
	}
	mydrv_read_offset = mydrv_write_offset = circle_invoked = 0;
	return 0;
}
void __exit mydrv_cleanup(void)
{
	kfree(mydrv_data);
	unregister_chrdev(MYDRV_MAJOR, DEVICE_NAME);
}
module_init(mydrv_init);
module_exit(mydrv_cleanup);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SUMIN");
MODULE_DESCRIPTION("nice");
MODULE_INFO(intree , "Y");
