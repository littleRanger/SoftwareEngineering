/***************************************************************************************************
*Copyright: qcc                                                                                   **
*Allrights reserved.                                                                               *
*                                                                                                  *
*filename: lab2                                                                                    *
*filelabel:                                                                                        *
*                                                                                                  *
*                                                                                                  *
*author: qcc                                                                                       *
*date: 2017.09.23                                                                                  *
*version: 1.0                                                                                      *
*                                                                                                  *
*                                                                                                  *
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int GetLocaltime()
{
    time_t now;
    struct tm *timenow;
    time(&now);
    timenow = localtime(&now);
    printf("Local time is :%s", asctime(timenow));
    return 0;
}
int add(int a, int b)
{
    int x=a+b;
    printf("the answer is %d\n", x);
    return 0;
}
int sub(int a, int b)
{
    if(a<b)
    {
        printf("the answer is -%d\n",b-a);
    }
    else
    {
        printf("the answer is %d\n",a-b);
    }
    return 0;
}
int multiply(int a, int b)
{
    printf("the answer is %d\n",a*b);
    return 0;
}
int divide(int a, int b)
{
    printf("the answer is %d\n",a/b);
    return 0;
}
int main()
{
    char cmd[128] = "";
    char user_name[128] ="";
    while(1)
    {
        int a,b;
        a=5;
        b=2;
        printf("Please Enter your command:\n");
        scanf("%s", cmd);
        if( 0==strcmp(cmd,"help"))
        {
            printf("This is a help command!");
            printf("Menu is a commandline program, version 1.0(C)\n");
 
            printf("Type 'help' to see this list.\ncommands are list:\n");
            printf("help\ntime\nadd\nsub\nmultiply\ndivide\nset:set user_name\nget:get user_name\nexit\n");
        }
        else if( 0==strcmp(cmd,"time"))
        {
            GetLocaltime();
        }
        else if( 0==strcmp(cmd,"add"))
        {
            add(a,b);
        }
        else if( 0==strcmp(cmd,"sub"))
        {
            sub(a,b);
        }
        else if( 0==strcmp(cmd, "multiply"))
        {
            multiply(a,b);
        }
        else if( 0==strcmp(cmd,"divide"))
        {
            divide(a,b);
        }
        else if( 0==strcmp(cmd,"set"))
        {
            printf("please set user_name:\n");
            scanf("%s",user_name);
        }
        else if( 0==strcmp(cmd,"get"))
        {
            if( 0==strlen(user_name))
            {
                printf("username not set!\n");
            }
            else
            {   
                printf("user name is %s\n",user_name);
            }
        }
        else if( 0==strcmp(cmd, "exit"))
        {
            exit(0);
        }
        else
        {
            printf("wrong cmd!");
        }
    }
}
