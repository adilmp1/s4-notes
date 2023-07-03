#include <stdio.h>
#include <string.h>
int main(int argc, char *arg[])
{
    FILE *fp = fopen(arg[2],"r");
    char temp[200];
    while(!feof(fp))
    {
        fgets(temp,sizeof(fp),fp);
        if(strstr(temp,arg[1]))
        {
            printf("%s\n",temp);
        }
    }
    fclose(fp);
}