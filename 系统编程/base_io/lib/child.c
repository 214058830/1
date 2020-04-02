/*  这是一个简单的源码文件，我要将这个文件中的代码进行打包最终
 *  生成一个动态库和静态库
 *  动态库和静态库都是给其它代码使用，意味着动态库和静态库中不能
 *  有main函数
 */
#include <stdio.h>
#include "child.h"
int print_test()
{
    printf("this is child!!!\n");
    return 0;
}
