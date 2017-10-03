/**************************************************************************************************/
/*Copyright: qcc                                                                                  */
/*Allrights reserved.                                                                             */
/*                                                                                                */
/*filename:     lab3                                                                              */
/*filelabel:                                                                                      */
/*LANGUAGE:     C                                                                                 */
/*TARGETENV:    ANY                                                                               */
/*AUTHER:       QCC                                                                               */
/*DATE:         2017.09.27                                                                        */
/*VERSION:      1.3                                                                               */
/*                                                                                                */
/*                                                                                                */
/**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linklist.h"
#define CMD_MAX_LEN 128
#define CMD_NUM 10
#define DESC_LEN 1024

int Help();
int Quit();
int Date();

static tDataNode head[] = 
{
    {"help", "This is help!", Help, &head[1]},
    {"version", "The program version is 1.3!", NULL, &head[2]},
    {"time", "Display current time!", Date, &head[3]},
    {"quit", "Bye", Quit, NULL}
};

int main()
{
    char cmd[CMD_MAX_LEN] = "";
    while(1)
    {
        printf("Please Enter your command>");
        scanf("%s", cmd);
        tDataNode *p=FindCMD(head,cmd);
        if(NULL==p)
        {
            printf("cmd not found!\n");
        }
        else
        {
            printf("%s--%s\n", p->cmd, p->desc);
            if(p->handler!=NULL)
                p->handler();                
        }
    }
    return 0;
}

int Help()
{
    ShowAllCMDs(head);
    return 0;
}

int Quit()
{
    exit(0);
    return 0;
}

int Date()
{
    time_t now;
    struct tm *timenow;
    timenow=localtime(&now);
    printf("Local data is :%s\n", asctime(timenow));
    return 0;
}

