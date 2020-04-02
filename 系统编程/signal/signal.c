/*  这是一个演示signal接口修改信号处理方式的demo
 *  信号的处理方式有三种：
 *      忽略
 *      默认
 *      自定义
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
/*
void sigcb(int signo)
{
    static int a = 1;
    static int b = 1;
    int c = 0;

    a++;
    sleep(10);
    b++;
    c = a + b;
    printf("recv signo:%d--%d\n", signo, c);
    return;
}*/
int main()
{
    int i = 0;
	signal(SIGINT, SIG_IGN);
    /*signal(SIGINT, sigcb);
    signal(SIGQUIT, sigcb);*/
    while(1) {
        
        printf("-----------\n");
        //kill(getpid(), SIGINT);
        if (++i == 3) {
            signal(SIGINT, SIG_DFL);
        }
        /*
        sigcb(SIGQUIT);*/
    }
    return 0;
}
