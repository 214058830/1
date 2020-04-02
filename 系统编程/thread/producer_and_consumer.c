//基于链表式的生产者消费者模型
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define CONSUMERS_COUNT 2
#define PRODUCERS_COUNT 2
struct msg{
	struct msg *next;
	int num;
};
struct msg *head = NULL;
pthread_cond_t cond;
pthread_mutex_t mutex;
pthread_t threads[CONSUMERS_COUNT+PRODUCERS_COUNT];
void *consumer(void *p)
{
	int num = *(int*)p;
	free(p);
	struct msg *mp;
	while(1){
		pthread_mutex_lock(&mutex);
		while ( head == NULL ) {
			printf("consume:[%d] begin wait a condition...\n", num);
			pthread_cond_wait(&cond, &mutex);
		}
		printf("consume:[%d] end wait a condition...\n", num);
		printf("consume:[%d] begin...\n", num);
		mp = head;
		head = mp->next;
		//从生产好的队列首开始取，先生产的后消费。
		pthread_mutex_unlock(&mutex);
		printf("Consume:[%d]->%d\n", num, mp->num);
		free(mp);
		printf("consume:[%d] end...\n", num);
		sleep(rand()%5);
	}
}
void *producer(void *p)
{
	struct msg *mp;
	int num = *(int*)p;
	free(p);
	while(1) {
		printf("producer:[%d] begin produce product...\n", num);
		mp = (struct msg*)malloc(sizeof(struct msg));
		mp->num = rand()%1000 + 1;
		printf("producer:[%d] produce %d\n", num, mp->num);
		pthread_mutex_lock(&mutex);
		mp->next = head;
		head = mp;
		//把生产好的放在生产队首，后生产的先使用.
		printf("producer:[%d] end...\n", num);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(rand()%5);
	}
}
int main(void){

	srand(time(NULL));
	pthread_cond_init(&cond, NULL);
	pthread_mutex_init(&mutex, NULL);
	int i;
	for(i=0; i<CONSUMERS_COUNT; i++) {
		int *p = (int*)malloc(sizeof(int));
		*p = i;
		pthread_create(&threads[i], NULL, consumer, (void*)p);
	}
	for(i=0; i<PRODUCERS_COUNT; i++) {
		int *p = (int*)malloc(sizeof(int));
		*p = i;
		pthread_create(&threads[CONSUMERS_COUNT+i], NULL, producer, (void*)p);
	}
	for (i=0; i<CONSUMERS_COUNT+PRODUCERS_COUNT; i++)
		pthread_join(threads[i], NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}
