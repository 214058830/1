
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	//	alarm(3);
    while(1) {
        printf("-------%d\n", getpid());
        sleep(1);
    }
    return 0;
}
