#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Hello World Kernel Module");
MODULE_VERSION("1.0");

static int __init hello_init(void) {
    printk(KERN_INFO "Hello, World!\n");
    return 0;  // Return 0 indicates successful module loading
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
