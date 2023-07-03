#include <stdio.h>
int mutex=1;
int empty=123,full=0;
int count=0;
int wait(int S)
{
    while(S<=0);
    return --S;
}
int signal(int S)
{
    return ++S;
}
void producer()
{
    mutex=wait(mutex);
    empty=wait(empty);
    full=signal(full);
    printf("producer produces %d",++count);
    mutex=signal(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    empty=signal(empty);
    full=wait(full);
    printf("consumer consumes %d",count--);
    mutex=signal(mutex);
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1. producer");
        printf("\n2. consumer");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                if(empty!=0 && mutex==1)
                {
                    producer();
                }
                else
                {
                    printf("Buffer is full");
                }
                break;
            case 2:
                if(full!=0 && mutex==1)
                {
                    consumer();
                }
                else
                {
                    printf("Buffer is empty");
                }
                break;
        }
    }
}
