#include <stdio.h>
int main(char *arg[])
{
    FILE * f1;
    FILE * f2;
    f1 = fopen(arg[1],"r");
    f2 = fopen(arg[2],"w");
    char c;
    while((c=fgetc(f1))!=EOF)
    {
        fputc(c,f2);
    }

    fclose(f1);
    fclose(f2);
}