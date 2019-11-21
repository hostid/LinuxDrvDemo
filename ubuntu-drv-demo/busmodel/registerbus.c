/*
 * @FileName: 
 * @Descripttion: 
 * @Author: jiangfeng.zhang(jiangfeng.zhang@aliyun.com)
 * @LastEditTime: 2019-11-21 15:39:44
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

int my_match(struct device *dev, struct device_driver *drv)
{
    printk("my_match was run\n");
    return !strncmp(dev->kobj.name, drv->name, strlen(drv->name));
}

struct bus_type my_bus_type = {
    .name = "my_bus",  //总线名称
    .match = my_match, //驱动与设备匹配函数
};

EXPORT_SYMBOL(my_bus_type);

static int my_bus_init(void)
{
    int ret;
    printk("insmode bus driver!\n");
    ret = bus_register(&my_bus_type);
    return ret;
}

static void my_bus_exit(void)
{
    printk("remmod bus driver!\n");
    bus_unregister(&my_bus_type);
}

module_init(my_bus_init);
module_exit(my_bus_exit);

MODULE_LICENSE("GPL");