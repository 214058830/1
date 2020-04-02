/*  这是一个实现管道符的demo
 *  命令：ps -ef |grep ssh
 *  一个进程运行ps程序，一个进程运行grep程序
 *  ps程序就需要将结果通过匿名管道传递给grep程序
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pid = -1;
    int pipefd[2] = {0};

    if (pipe(pipefd) < 0 ) {
        perror("pipe error");
        return -1;
    }
    pid = fork();
    if (pid < 0) {
        perror("fork error");
        return -1;
    }else if (pid == 0) {
        //子进程运行grep程序处理ps的结果（从管道读数据）
        dup2(pipefd[0], 0);
        close(pipefd[1]);
        execl("/bin/grep", "grep", "ssh", NULL);
    }else {
        //父进程运行ps程序，将结果写入管道
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        execl("/bin/ps", "ps", "-ef", NULL);
    }
    return 0;
}
