#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sigcb(int signo)
{
    while(waitpid(-1, NULL, WNOHANG) > 0){
		printf("wait child success\n");
	}
    printf("have child exit!!\n");
}
int main()
{
    signal(SIGCHLD, sigcb);
    int pid = fork();
    if (pid == 0) {
        exit(0);
    }
    while(1) {
        printf("------\n");
        sleep(1);
    }
    return 0;
}
