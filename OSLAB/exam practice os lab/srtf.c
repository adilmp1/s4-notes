#include <stdio.h>
typedef struct{
    int at,bt,ct,tat,wt,rt;
}pcb;

int main()
{
    int n,sJob,sTime;
    int sum=0,totalTAT=0,totalWT=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    pcb a[n];
    printf("Enter the burst time of n processes: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].at);
        scanf("%d",&a[i].bt);
        a[i].rt = a[i].bt;
    }
    int completed=0,currentTime=0;
    while(completed<n)
    {
        sJob = -1;
        sTime = 99999;
        for(int i=0;i<n;i++)
        {
            if(a[i].at<=currentTime && a[i].rt>0 && a[i].rt<sTime)
            {
                sJob=i;
                sTime=a[i].rt;
            }
        }
        if(sJob==-1)
        {
            currentTime++;
        }
        else
        {
            currentTime++;
            a[sJob].rt--;
            if(a[sJob].rt==0)
            {
                completed++;
                a[sJob].ct = currentTime;
                a[sJob].tat = a[sJob].ct-a[sJob].at;
                a[sJob].wt = a[sJob].tat-a[sJob].bt;
                totalTAT+=a[sJob].tat;
                totalWT+=a[sJob].wt;
            }
        }
    }
    printf("\nAT\tBT\tCT\tTAT\tWT");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d",a[i].at, a[i].bt, a[i].ct, a[i].tat, a[i].wt);
    }
    printf("\n\n%f\t%f",(float) totalWT/n,(float) totalTAT/n);
    
}