#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
MODULE_AUTHOR("Ken Tokura");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static dev_t dev;
static struct cdev cdv;

static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
	printk(KERN_INFO "led_write is called\n");
	return 1; //読み込んだ文字数を返す(この場合はダミーの1)
}

static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.write = led_write
};

static int __init init_mod(void) //カーネルモジュールの初期化
{
	// デバイス番号を取得
	int retval;
	retval =  alloc_chrdev_region(&dev, 0, 1, "myled");
	if(retval < 0){
		printk(KERN_ERR "alloc_chrdev_region failed.\n");
		return retval;
	}
	printk(KERN_INFO "%s is loaded. major:%d\n",__FILE__,MAJOR(dev));

	// キャラクタデバイスを初期化してカーネルに登録
	cdev_init(&cdv, &led_fops);
	retval = cdev_add(&cdv, dev, 1);
	if(retval < 0){
		printk(KERN_ERR "cdev_add failed. major:%d, minor:%d",MAJOR(dev),MINOR(dev));
		return retval;
	}

	return 0;
}

static void __exit cleanup_mod(void) //後始末
{
	cdev_del(&cdv); //キャラクタデバイスの破棄
	unregister_chrdev_region(dev, 1); //デバイス番号の開放
	printk(KERN_INFO "%s is unloaded. major:%d\n",__FILE__,MAJOR(dev));
}

module_init(init_mod); //マクロで関数を登録
module_exit(cleanup_mod); //同上
