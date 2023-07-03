#include <stdio.h>
typedef struct{
    int at,bt,ct,tat,wt;
}pcb;

void sortWithBurstTime(pcb a[],int n)
{
    pcb temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j].bt>a[j+1].bt)
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n;
    int sum=0,totalTAT=0,totalWT=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    pcb a[n];
    printf("Enter the burst time of n processes: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].bt);
        a[i].at=0;
    }
    sortWithBurstTime(a,n);
    for(int i=0;i<n;i++)
    {
        sum+=a[i].bt;
        a[i].ct = sum;
        a[i].tat = a[i].ct-a[i].at;
        a[i].wt = a[i].tat-a[i].bt;
        totalTAT+=a[i].tat;
        totalWT+=a[i].wt;
    }
    // float avgWT = 
    printf("%f\t%f",(float) totalWT/n,(float) totalTAT/n);
    
}