#include <stdio.h>
int queue[200];
int front = -1, rear = -1;
typedef struct
{
    int id, at, bt, ct, tat, wt, rt, status;
} pcb;
void enqueue(int item)
{
    if (front == -1 && rear == -1)
    {
        front++;
    }
    queue[++rear] = item;
}

int dequeue()
{
    if (front == -1)
    {
        return -1;
    }
    int item = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return item;
}

int main()
{
    int n, completed = 0, time = 0, qExpire = 0, dequeuedItem = -1, quantum;
    int totalTAT = 0, totalWT = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    pcb a[n];
    printf("Enter arrival time and burst time of n processes\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].at);
        scanf("%d", &a[i].bt);
        a[i].status = 0;
        a[i].rt = a[i].bt;
        a[i].id=i+1;
    }
    printf("Enter quantum: ");
    scanf("%d", &quantum);
    while (time != a[0].at)
    {
        time++;
    }
    enqueue(0);
    a[0].status = 1;

    while (completed < n)
    {
        if (dequeuedItem == -1)
        {
            dequeuedItem = dequeue();
        }
        time++;

        for (int i = 0; i < n; i++)
        {
            if (a[i].status == 0 && a[i].at <= time)
            {
                enqueue(i);
                a[i].status = 1;
            }
        }

        if (dequeuedItem != -1)
        {
            if (qExpire != quantum && a[dequeuedItem].rt > 0)
            {
                qExpire++;
                a[dequeuedItem].rt--;
            }
            if (a[dequeuedItem].rt == 0)
            {
                a[dequeuedItem].ct = time;
                a[dequeuedItem].tat = time - a[dequeuedItem].at;
                a[dequeuedItem].wt = a[dequeuedItem].tat - a[dequeuedItem].bt;
                completed++;
                totalTAT += a[dequeuedItem].tat;
                totalWT += a[dequeuedItem].wt;
                qExpire = 0;
                dequeuedItem = -1;
            }
            else if (qExpire == quantum)
            {
                enqueue(dequeuedItem);
                qExpire = 0;
                dequeuedItem = -1;
            }
        }
    }
    printf("\nID\tAT\tBT\tCT\tTAT\tWT");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", a[i].id, a[i].at, a[i].bt, a[i].ct, a[i].tat, a[i].wt);
    }
    printf("\n\nAverage Waiting Time : %f", ( (float) totalWT / n));
    printf("\nAverage Turn Around Time : %f\n", ( (float) totalTAT / n));
}