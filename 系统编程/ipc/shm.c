/*  这是一块共享内存的demo，共享数据
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>

#define IPC_KEY 0x01234567
int main()
{
    int shmid = -1;
    shmid = shmget(IPC_KEY, 32, IPC_CREAT|0664);
    if (shmid < 0) {
        printf("shmget error\n");
        return -1;
    }

    void *shm_start = shmat(shmid, NULL, SHM_RND);
    if (shm_start == (void*)-1) {
        perror("shmat error");
        return -1;
    }

    int i = 0;
    while(1) {
        sprintf(shm_start, "%d\n", i++);
        sleep(1);
    }
    shmdt(shm_start);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
