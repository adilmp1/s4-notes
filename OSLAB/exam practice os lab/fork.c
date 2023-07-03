#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid = fork();
    if(pid<0)
    {
        printf("Fork failed");
    }
    else if(pid==0)
    {
        printf("Fork success\n");
        printf("PID: %d",getpid());
    }
    else
    {
        printf("Inside parent\n");
    }
}