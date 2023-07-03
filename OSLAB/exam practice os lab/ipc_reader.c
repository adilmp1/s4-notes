#include <stdio.h>
#include <sys/shm.h>
int main()
{
    int key = ftok("shm44",442);
    int shmid = shmget(key,512,0666 | IPC_CREAT);
    char * shmadder = shmat(shmid,NULL,0);
    puts(shmadder);
}
