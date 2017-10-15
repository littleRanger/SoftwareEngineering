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
#include "linktable.h"
#define CMD_MAX_LEN 128
#define CMD_NUM 10
#define DESC_LEN 1024

int Help();
int Quit();
int Date();

typedef struct DataNode
{
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int (*handler)();
}tDataNode;

tDataNode* FindCMD(tLinkTable *head, char *cmd)
{
    
    tDataNode *p=(tDataNode*)GetLinkTableHead(head);
    while(p!=NULL)
    {
        if(0==strcmp(p->cmd, cmd))
        {
            return p;
        }
        p=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)p);
    }
    return NULL;
}

int ShowAllCMDs(tLinkTable *head)
{
    printf("Menu List:\n");
    tDataNode *p=(tDataNode*)GetLinkTableHead(head);
    while(p!=NULL)
    {
        printf("%s--%s\n", p->cmd, p->desc);
        p=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)p);
    }
    return 0;
}

int InitMenuData(tLinkTable **ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();
    tDataNode *pDataNode=(tDataNode*)malloc(sizeof(tDataNode));
    pDataNode->cmd="help";
    pDataNode->desc="This is help!";
    pDataNode->handler=Help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pDataNode);
    pDataNode=(tDataNode*)malloc(sizeof(tDataNode));
    pDataNode->cmd="version";
    pDataNode->desc="menulist version 1.4";
    pDataNode->handler=NULL;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pDataNode);
    pDataNode=(tDataNode*)malloc(sizeof(tDataNode));
    pDataNode->cmd="time";
    pDataNode->desc="show system time!";
    pDataNode->handler=Date;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pDataNode);
    pDataNode=(tDataNode*)malloc(sizeof(tDataNode));
    pDataNode->cmd="quit";
    pDataNode->desc="Bye";
    pDataNode->handler=Quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pDataNode);
    return 0;
}
tLinkTable *head=NULL;
int main()
{
    InitMenuData(&head);
    char cmd[CMD_MAX_LEN] = "";
    while(1)
    {
        printf("Please Enter your command>");
        scanf("%s", cmd);
//        printf("a");
  //      if(cmd[0]=="\0")
    //        printf("bb");
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

