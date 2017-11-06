#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "menu.h"

int MenuConfig(char * cmd, char * desc, int (*handler)(int argc, char *argv[]));
int ExcuteMenu();
int Quit(int argc, char *argv[]);
int GetLocaltime(int argc, char *argv[]);
int Fl(int argc, char *argv[]);
int atoi_s(char s[],int len);
int argtest(int argc, char **argv)
{
    const char *optString = "lah";
    opterr = 0;
    int opt;
    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'l':
                printf("this -l option\n");
                break;            
            case 'a':
                printf("this -a option\n");
                break;
            case 'h':
                printf("in this cmd, you have 3 option can use:\n");
                printf("-l\n");
                printf("-a\n");
                printf("-h\n");
                break;
            default:
                break;
        }
    }
    // reset global valuable optind
    optind = 0;
    return 0;
}
int main(int argc, char * argv[])
{
    MenuConfig("quit","exit from the menu!",Quit);
    MenuConfig("time","show the BeiJingTime!",GetLocaltime);
    MenuConfig("factorial","nx(n-1)x...x1",Fl);
    MenuConfig("argtest","a test for getopt!",argtest);
    ExcuteMenu();
    return 0;
}

int Fl(int argc, char *argv[])
{
    int i =0,sum=1,x;
    //printf("%d\n",strlen(argv[1]));
    if(argc!=2)
        printf("wrong input!\n");
    else if(atoi_s(argv[1],strlen(argv[1])-1)==-1)
        printf("u must input a num\n");
    else
    {
        x=atoi_s(argv[1],strlen(argv[1])-1);      
        for(i=1;i<=x;i++)       
            sum=sum*i;
        printf("factorial(%d)=%d\n",x,sum);
    }
    return 0;
}
int GetLocaltime(int argc, char *argv[])
{
    time_t now;
    struct tm *timenow;
    time(&now);
    timenow = localtime(&now);
    printf("Local time is :%s", asctime(timenow));
    return 0;
}

int Quit(int argc, char * argv[])
{
    exit(0);
}
int atoi_s(char s[],int len)
{
    int i=0,n;

    while(i<len)
    {
        if(isdigit(s[i]))
            i++;
        else
            return -1;
    }
    for(n=0,i=0;isdigit(s[i]);i++)
    { 
        n=10*n+(s[i]-'0');//将数字字符转换成整形数字
    }
        return n;
}
