/*  这是一个演示文件描述符分配规则的demo
 *      1. 文件描述符是一个数字，并且这个数字是一个结构体数组的下标
 *  分配规则：
 *      寻找最小的未使用的下标
 *  一个进程运行起来之后，默认打开的三个文件：
 *      标准输入    标准输出    标准错误
 *      stdin       stdout      stderr
 *      0           1           2
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd = -1;

    fd = open("./tmp.txt", O_RDWR | O_CREAT);
    if (fd < 0) {
        perror("open error");
        return -1;
    }

    dup2(fd, 1);

    printf("fd:%d\n", fd);
    fflush(stdout);
    close(fd);
    return 0;
}
