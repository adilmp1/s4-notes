#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc,char * arg[])
{
    char temp[200];
    FILE * f1 = fopen(arg[2],"r");
    while(!feof(f1))
    {
        fgets(temp,sizeof(f1),f1);
        if(strstr(temp,arg[1]))
        {
            printf("%s\n",temp);
        }

    }

}   