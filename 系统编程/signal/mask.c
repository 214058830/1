/*  这是一个演示信号阻塞的demo
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    sigset_t new_block;
    sigset_t old_block;
    sigemptyset(&new_block);
    sigfillset(&new_block);
    sigprocmask(SIG_BLOCK, &new_block, &old_block);
	//不按回车不往下走
    getchar();
	//接除阻塞
    sigset_t pending;
    sigemptyset(&pending);
    sigpending(&pending);
    if (sigismember(&pending, SIGINT)) {
        printf("SIGINT is blocked!!\n");
    }
    //解除阻塞
    sigprocmask(SIG_UNBLOCK, &new_block, NULL);
    //将原先阻塞集合中的信号还原回去
    sigprocmask(SIG_SETMASK, &old_block, NULL);

    return 0;
}
