/*  这是一个命名管道的实现demo，实现两个进程聊天功能
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    //char *file = "./test.fifo";
    umask(0);
    //if (mkfifo(file, 0664) < 0) {
	if(mkfifo("./test.fifo", 0664) < 0){
        if (errno == EEXIST) {
            printf("fifo exist!!\n");
        }else {
            perror("mkfifo");
            return -1;
        }
    }
	int fd = open("./test.fifo", O_RDONLY);
    //int fd = open(file, O_RDONLY);
    if (fd < 0) {
        perror("open error");
        return -1;
    }
    printf("open fifo success!!\n");
    while(1) {
        char buff[1024];
        memset(buff, 0x00, 1024);
        int ret = read(fd, buff, 1024);
        if (ret > 0) {
            printf("peer say:%s\n", buff);
        }
    }
    close(fd);
    return 0;
}
