/*  这是一个命名管道的实现demo，实现两个进程聊天功能
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    char *file = "./test.fifo";
    umask(0);
    if (mkfifo(file, 0664) < 0) {
        if (errno == EEXIST) {
            printf("fifo exist!!\n");
        }else {
            perror("mkfifo");
            return -1;
        }
    }
    int fd = open(file, O_WRONLY);
    if (fd < 0) {
        perror("open error");
        return -1;
    }
    printf("open fifo success!!\n");
    while(1) {
        printf("input: ");
        fflush(stdout);
        char buff[1024] = {0};
        scanf("%s", buff);
        write(fd, buff, strlen(buff));
    }
    close(fd);
    return 0;
}
