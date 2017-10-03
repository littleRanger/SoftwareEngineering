#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

tDataNode* FindCMD(tDataNode *head, char *cmd)
{
    if(NULL==cmd)
        return NULL;
    tDataNode *p=head;
    while(p!=NULL)
    {
        if(0==strcmp(p->cmd, cmd))
        {
            return p;
        }
        else
        {
            p=p->next;
        }
    }
    return NULL;
}

int ShowAllCMDs(tDataNode *head)
{
    printf("Menu List:\n");
    tDataNode *p=head;
    while(p!=NULL)
    {
        printf("%s--%s\n", p->cmd, p->desc);
        p=p->next;
    }
    return 0;
}
