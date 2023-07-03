#include <stdio.h>
#include <sys/shm.h>

int main()
{
    int key  = ftok("shm",2);
    int shmid = shmget(key,1024,0666 | IPC_CREAT);
    char * sdkfjh = shmat(shmid,NULL,0);
    printf("Enter the data to store: ");
    fgets(sdkfjh,50,stdin);
    shmdt(sdkfjh);
}