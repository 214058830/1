/*  这是一个匿名管道的demo
 *      匿名管道操作：
 *          创建：pipe
 *          读写：read write
 *      匿名管道仅能用于具有亲缘关系的进程间通信
 *      创建匿名管道必须在创建子进程之前，否则子进程将无法复制
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    pid_t pid;
    int pipefd[2] = {0};

    if (pipe(pipefd) < 0) {
        perror("pipe error");
        return -1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork error");
        return -1;
    }else if (pid == 0) {
        //子进程 读
        sleep(3);
        close(pipefd[1]);
        char buff[1024] = {0};
        read(pipefd[0], buff, 11);
        printf("child:%s\n", buff);
        read(pipefd[0], buff, 11);
        printf("child:%s\n", buff);
        close(pipefd[0]);
    }else {
        //父进程 写
        close(pipefd[0]);
        char *ptr = "hello world";
        write(pipefd[1], ptr, strlen(ptr));
        write(pipefd[1], ptr, strlen(ptr));
        close(pipefd[1]);
    }
    return 0;
}
