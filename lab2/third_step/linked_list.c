#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Kernel Module for Managing Linked List");
MODULE_VERSION("1.0");

// Define a structure for our list nodes
struct my_node {
    int data;
    struct list_head list; // Kernel's list_head structure
};

// Initialize the head of the linked list
static LIST_HEAD(my_linked_list);

// Module initialization function
static int __init linked_list_init(void)
{
    struct my_node *node;
    int i;

    printk(KERN_INFO "Initializing Linked List Module\n");

    // Add 5 nodes with integer data values
    for (i = 1; i <= 5; i++) {
        node = kmalloc(sizeof(*node), GFP_KERNEL);
        if (!node) {
            printk(KERN_ERR "Memory allocation failed for node\n");
            return -ENOMEM;
        }
        node->data = i;
        INIT_LIST_HEAD(&node->list); // Initialize the list within the node
        list_add_tail(&node->list, &my_linked_list); // Add node to the list
        printk(KERN_INFO "Added node with data: %d\n", node->data);
    }

    // Traverse the list and print the data
    printk(KERN_INFO "Traversing the linked list:\n");
    list_for_each_entry(node, &my_linked_list, list) {
        printk(KERN_INFO "Node data: %d\n", node->data);
    }

    return 0;
}

// Module cleanup function
static void __exit linked_list_exit(void)
{
    struct my_node *node, *tmp;

    printk(KERN_INFO "Cleaning up Linked List Module\n");

    // Safely traverse and delete all nodes
    list_for_each_entry_safe(node, tmp, &my_linked_list, list) {
        printk(KERN_INFO "Removing node with data: %d\n", node->data);
        list_del(&node->list); // Remove node from the list
        kfree(node); // Free allocated memory
    }

    printk(KERN_INFO "Linked List Module cleaned up successfully\n");
}

module_init(linked_list_init);
module_exit(linked_list_exit);
