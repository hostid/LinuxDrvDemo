/*
 * @FileName: 
 * @Descripttion: 
 * @Author: jiangfeng.zhang(jiangfeng.zhang@aliyun.com)
 * @LastEditTime: 2019-11-21 16:02:24
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

extern struct bus_type my_bus_type;

int my_probe(struct device *dev)
{
    printk("driver and devicre match ok.\n");
    return 0;
}

struct device_driver my_driver =
    {
        .name = "jiangfeng",       //驱动名字
        .bus = &my_bus_type, //属于哪条总线
        .probe = my_probe,
};

static int my_driver_init()
{
    return driver_register(&my_driver);
}

static int my_driver_exit()
{
    driver_unregister(&my_driver);
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");