#include <stdio.h>
#include <dirent.h>
int main()
{
    DIR *p;
    p = opendir("./");
    struct dirent *d;
    while(d=readdir(p))
    {
        printf("%s\n",d->d_name);
    }
}