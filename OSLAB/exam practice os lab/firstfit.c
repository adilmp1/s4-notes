#include <stdio.h>
void display(int allocation[],int n,int process[])
{
    printf("\nPNo\tPSize\tBlockNo");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t%d\t",i+1,process[i]);
        if(allocation[i]!=-1)
        {
            printf("%d",allocation[i]);
        }
        else
        {
            printf("Not alloc");
        }
    }
}
void firstfit(int block[],int m, int process[], int n)
{
    int allocation[n];
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(block[j]>=process[i])
            {
                allocation[i]=j+1;
                block[j]-=process[i];
                break;
            }
        }
    }
    display(allocation,n,process);
}
void bestfit(int block[],int m, int process[], int n)
{
    int allocation[n];
    int best;
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        best=-1;
        for(int j=0;j<m;j++)
        {
            if(block[j]>=process[i])
            {
                if(best==-1 || block[j]<block[best])
                {
                    best=j;
                }
            }
        }
        if(best!=-1)
        {
            allocation[i]=best+1;
            block[best]-=process[i];
        }
    }
    display(allocation,n,process);
}
void worstfit(int block[],int m, int process[], int n)
{
    int allocation[n];
    int best;
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        best=-1;
        for(int j=0;j<m;j++)
        {
            if(block[j]>=process[i])
            {
                if(best==-1 || block[j]>block[best])
                {
                    best=j;
                }
            }
        }
        if(best!=-1)
        {
            allocation[i]=best+1;
            block[best]-=process[i];
        }
    }
    display(allocation,n,process);
}
int main()
{
    int block[]={100,500,200,300,600};
    int process[]={212, 417, 112, 426};
    int m=5,n=4;
    worstfit(block,m,process,n);
}