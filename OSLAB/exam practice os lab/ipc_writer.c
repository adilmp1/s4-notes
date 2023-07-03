#include <stdio.h>
#include <sys/shm.h>
int main()
{
    int key = ftok("s23452345434hm",23423423323);
    int shmid = shmget(key,1024,0666 | IPC_CREAT);
    char * shmadder = shmat(shmid,NULL,0);
    printf("Enter data to store:    ");
    fgets(shmadder,50,stdin);
    shmdt(shmadder);
}
