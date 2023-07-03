#include <stdio.h>
int q[100], front = -1, rear = -1;

struct process
{
    int id, at, tat, bt, wt, rt, ct, status;
} a[20];

void enqueue(int j)
{
    if (front == -1 && rear == -1)
        front++;
    rear++;
    q[rear] = j;
}

int dequeue()
{
    if (front == -1)
        return -1;
    int item;
    item = q[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return (item);
}

void main()
{
    int n, quantum, time = 0, completed = 0, current = 0, i, dequeuedItem = -1, qExpire = 0;
    float totalWT = 0, totalTAT = 0;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter the id,  arrival time and burst time of n processes: \n");
    for (i = 0; i < n; i++) // Input process details
    {
        a[i].id = i + 1;
        a[i].status = 0;
        scanf("%d", &a[i].at);
        scanf("%d", &a[i].bt);
        a[i].rt = a[i].bt;
    }
    printf("\nEnter time quantum : ");
    scanf("%d", &quantum);

    // Waiting for first process to arrive
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
        // Loop to check for new process
        for (i = 0; i < n; i++)
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
                a[dequeuedItem].rt--;
                qExpire++;
            }
            if (a[dequeuedItem].rt == 0)
            {
                a[dequeuedItem].ct = time;
                a[dequeuedItem].tat = a[dequeuedItem].ct - a[dequeuedItem].at;
                a[dequeuedItem].wt = a[dequeuedItem].tat - a[dequeuedItem].bt;
                completed++;
                totalWT += a[dequeuedItem].wt;
                totalTAT += a[dequeuedItem].tat;
                dequeuedItem = -1;
                qExpire = 0;
            }
            else if (qExpire == quantum)
            {
                enqueue(dequeuedItem);
                dequeuedItem = -1;
                qExpire = 0;
            }
        }
    }

    printf("\nID\tAT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", a[i].id, a[i].at, a[i].bt, a[i].ct, a[i].tat, a[i].wt);
    }
    printf("\n\nAverage Waiting Time : %f", (totalWT / n));
    printf("\nAverage Turn Around Time : %f\n", (totalTAT / n));
}