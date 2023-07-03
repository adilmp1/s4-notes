#include <stdio.h>
typedef struct{
    int at,bt,ct,tat,wt;
}pcb;

int main()
{
    int n;
    int sum=0,totalTAT=0,totalWT=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    pcb a[n];
    printf("Enter the arrival time and burst time of n processes: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].at);
        scanf("%d",&a[i].bt);
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