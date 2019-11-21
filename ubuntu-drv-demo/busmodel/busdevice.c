/*
 * @FileName: 
 * @Descripttion: 
 * @Author: jiangfeng.zhang(jiangfeng.zhang@aliyun.com)
 * @LastEditTime: 2019-11-21 15:44:04
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
 
extern struct bus_type my_bus_type;
 
struct device my_dev =
{
    .init_name = "jiangfeng",
    .bus = &my_bus_type
};
 
static int my_device_init()
{
    int ret;
    ret = device_register(&my_dev);
    return ret;
}
 
static void my_device_exit()
{
    device_unregister(&my_dev);
}
 
module_init(my_device_init);
module_exit(my_device_exit);
 
MODULE_LICENSE("GPL");