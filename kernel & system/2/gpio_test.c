#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/gpio.h>

#define GPIO 23
#define GPIO2 24
static int __init ofd_init(void)
{
		gpio_is_valid(GPIO);
		gpio_direction_output(GPIO,1);
		gpio_is_valid(GPIO2);
		gpio_direction_output(GPIO2,1);
		printk(KERN_INFO,"Good");
		return 0;
}
static void __exit ofd_exit(void)
{
	gpio_is_valid(GPIO);
	gpio_direction_output(GPIO,0);
	gpio_is_valid(GPIO2);
	gpio_direction_output(GPIO2,0);
	printk(KERN_INFO,"bye");
}
module_init(ofd_init);
module_exit(ofd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SOHNQUIXOTE");
MODULE_DESCRIPTION("EXAMPLE");
