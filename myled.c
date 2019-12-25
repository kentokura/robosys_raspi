#include <linux/module.h>

static int __init init_mod(void) //カーネルモジュールの初期化
{
	return 0;
}

static void __exit cleanup_mod(void) //後始末
{
}

module_init(init_mod); //マクロで関数を登録
module_exit(cleanup_mod); //同上
