#include<errno.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int i;
    DIR *dp;
    struct dirent *dirp;
    if(argc==1)
    {
        perror("usage:a.exe filename\n");
        exit(0);
    }
    for(i=1;i<argc;i++)
    {
        printf("%s\n*********************\n",argv[i]);
        if((dp=opendir(argv[i]))==NULL)
        {
            fprintf(stderr,"cannot open %s\n",argv[i]);
            continue;
        }
        while((dirp=readdir(dp))!=NULL)
            printf("    %s\n",dirp->d_name);
        closedir(dp);
    }
    exit(0);
}
