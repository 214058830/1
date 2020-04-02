/*  因为signal这个接口有linux版本的差异性，因此大佬们都喜欢使用
 *  sigaction这个接口来替代signal函数，他的功能也是自定义信号的处理
 *  方式，并且signal函数内部也是通过sigaction实现的。
 *
 *  这是sigaction接口的使用demo
 *//*
  struct sigaction {
      void (*sa_handler)(int); //处理函数
      void (*sa_sigaction)(int, siginfo_t *, void *);//处理函数
      sigset_t   sa_mask;//在处理信号的时候可以通过这个mask暂时阻
                        塞一些信号，处理完毕之后会还原回去
      int        sa_flags;//决定了我们使用哪个回调接口，并且还有
                        一些其它的选项信息
      void     (*sa_restorer)(void);//暂时不讲
  };
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigcb1(int signo, siginfo_t *info, void *cont)
{
    printf("recv signo:%d---param:%d\n", signo, info->si_int);
}
void sigcb(int signo)
{
    printf("recv signo:%d\n", signo);
}
int main()
{
    struct sigaction new_act;
    struct sigaction old_act;

    //我重新定义处理方式的信号是SIGINT SIGQUIT
    //int sigaction(int signum, const struct sigaction *act,
    //      struct sigaction *oldact);
    //  signum: 信号编号
    //  act：   新的处理方式
    //  oldact：保存原有处理方式

    //这个操作是我们一般性的更改一个信号的处理方式，这种处理方式
    //sa_flags = 0代表我们使用的回调接口是sa_handler；
    sigemptyset(&new_act.sa_mask);
    new_act.sa_flags = 0;
    new_act.sa_handler = sigcb;
    sigaction(SIGINT, &new_act, &old_act);

    //这个操作是用于传递信号同时携带参数的情况，sa_flags需要被指定
    //为：SA_SIGINFO，并且这时候回调需要使用sa_sigaction
    sigemptyset(&new_act.sa_mask);
    new_act.sa_flags = SA_SIGINFO;
    new_act.sa_sigaction = sigcb1;
    sigaction(SIGQUIT, &new_act, &old_act);
    while(1) {
        sleep(1);
        kill(getpid(), SIGINT);
        //int sigqueue(pid_t pid, int sig, union sigval)
        //这个函数不仅可以发送信号，还可以顺便携带一个参数
        //  pid:    进程ID
        //  sig：   信号编号
        //  sigval：参数
        union sigval val;
        val.sival_int = 999;
        sigqueue(getpid(), SIGQUIT, val);
    }

    return 0;
}
