#include <stdio.h>
#include <sys/shm.h>
int main()
{
    int key = ftok("s2345234534hm",2342342323);
    int shmid = shmget(key,512,0666 | IPC_CREAT);
    char * shmadder = shmat(shmid,NULL,0);
    printf("Enter data to store:    ");
    fgets(shmadder,50,stdin);
    shmdt(shmadder);
}
