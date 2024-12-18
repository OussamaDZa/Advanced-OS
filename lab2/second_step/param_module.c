#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple module that accepts parameters");
MODULE_VERSION("1.0");

static int param_value = 42;  // Default value for the parameter

module_param(param_value, int, S_IRUGO);  // Define the module parameter
MODULE_PARM_DESC(param_value, "An example parameter that holds an integer value");

static int __init param_module_init(void) {
    printk(KERN_INFO "Module loaded! param_value = %d\n", param_value);
    return 0;
}

static void __exit param_module_exit(void) {
    printk(KERN_INFO "Module unloaded! param_value was = %d\n", param_value);
}

module_init(param_module_init);
module_exit(param_module_exit);
