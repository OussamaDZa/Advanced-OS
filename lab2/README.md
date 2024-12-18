# Linux Kernel Module Execution Guide

This project demonstrates how to compile, insert, and remove a Linux kernel module. Follow the steps below to execute the module successfully on your Linux system.

## Prerequisites

- A Linux-based operating system with kernel headers installed.
- Basic understanding of Linux commands.
- Sufficient permissions (root or sudo) to execute kernel-related operations.

## Files in the Project

- `module.c` - The source code for the kernel module.
- `Makefile` - The file used to compile the kernel module.

## Steps to Execute

### 1. Compile the Kernel Module
To compile the kernel module, use the `make` command:
```bash
make
```
This will generate a `.ko` (kernel object) file in the current directory.

### 2. Insert the Kernel Module
To load the compiled kernel module into the Linux kernel, use the `insmod` command:
```bash
sudo insmod module.ko
```
You can verify that the module is loaded by checking the kernel log:
```bash
dmesg | tail
```
Alternatively, you can use the `lsmod` command to list all currently loaded modules:
```bash
lsmod | grep module
```

### 3. Remove the Kernel Module
To remove the kernel module from the Linux kernel, use the `rmmod` command:
```bash
sudo rmmod module
```
Check the kernel log again to ensure the module was removed successfully:
```bash
dmesg | tail
```

## Cleaning Up
To clean up the compiled files, use the `make clean` command:
```bash
make clean
```

## Notes
- Make sure to adjust the `module.c` code and `Makefile` as per your project's requirements.
- Always test kernel modules in a safe environment, as they run in kernel space and can impact the system's stability.

## Troubleshooting
- If `make` fails, ensure you have the kernel headers installed:
  ```bash
  sudo apt install linux-headers-$(uname -r)  # For Debian/Ubuntu
  ```
- Use `modinfo module.ko` to view detailed information about the module if issues arise.