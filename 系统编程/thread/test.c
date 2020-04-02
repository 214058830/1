//简单的线程代码
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *rout() {
	while(1){
		printf("I am thread\n");
		sleep(1);
	} 
}
void *rout1(){
	while(1){
		sleep(1);
		printf("I am thread 1\n");
	}
}
int main()
{
	pthread_t tid, tid1;
	int ret;
	if((ret=pthread_create(&tid, NULL, rout, NULL)) != 0){
		fprintf(stderr, "pthread_create : %s\n", strerror(ret));
		exit(EXIT_FAILURE);
	}
	pthread_create(&tid1, NULL, rout1, NULL);
	pthread_join(tid, NULL);
	pthread_join(tid1, NULL);
	printf("I'am main thread\n");
	sleep(1);
	return 0;
}
