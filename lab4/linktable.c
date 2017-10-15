/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"


tLinkTable * CreateLinkTable()
{
    tLinkTable *pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if( NULL == pLinkTable)
    {
        printf("create linktable failed!");
        return NULL;
    }
    pLinkTable->pHead=NULL;
    pLinkTable->pTail=NULL;
    pLinkTable->SumOfNode=0;
    return pLinkTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return FAILURE;
    }
    while(NULL!=pLinkTable->pHead)
    {
        tLinkTableNode *p=pLinkTable->pHead;
        pLinkTable->pHead=p->pNext;
        free(p);
    }
    pLinkTable->pHead=NULL;
    pLinkTable->pTail=NULL;
    pLinkTable->SumOfNode=0;
    free(pLinkTable);
    return SUCCESS;    
}
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if( NULL==pLinkTable || NULL==pNode)
    {
        return FAILURE;
    }
    if(pLinkTable->pHead==NULL)
    {
        pLinkTable->pHead=pNode;
        pLinkTable->pTail=pNode;
        pLinkTable->SumOfNode=1;
    }
    else
    {
        pLinkTable->pTail->pNext=pNode;
        pLinkTable->pTail=pNode;
        pNode->pNext=NULL;
        pLinkTable->SumOfNode++;
    }
    return SUCCESS;
}
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if( NULL==pLinkTable || NULL==pNode)
    {
        return FAILURE;
    }
    if(pLinkTable->SumOfNode==0)
    {
        printf("No Node in the table!\n");
        return FAILURE;
    }
    tLinkTableNode *p=pLinkTable->pHead;
    if(pLinkTable->pHead==pNode)
    {
        if(pLinkTable->SumOfNode==1)
        {
            pLinkTable->pHead=NULL;
            pLinkTable->pHead=NULL;
            pLinkTable->SumOfNode=0;
            free(pNode);
            return SUCCESS;
        }
        else
        {
            pLinkTable->pHead=pNode->pNext;
            pLinkTable->SumOfNode--;
            free(pNode);
            return SUCCESS;
        }
    }
    tLinkTableNode *pre=NULL;
    while(p!=NULL)
    {   
        
        if(p==pNode)
            break;
        pre=p;
        p=p->pNext;
    }
    if(p!=NULL)
    {
        if(pLinkTable->pTail==pNode)
        {
            pre->pNext=NULL;
            pLinkTable->pTail=pre;
            pLinkTable->SumOfNode--;
            free(pNode);
            return SUCCESS;
        }
        else
        {
            pre->pNext=pNode->pNext;
            pLinkTable->SumOfNode--;
            free(pNode);
            return SUCCESS;
        }
    }
    else
    {
        return FAILURE;
    }
}
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable->pHead==NULL)
        return NULL;
    else
        return pLinkTable->pHead;
}
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if(pLinkTable==NULL || pNode==NULL)
        return NULL;
    tLinkTableNode *p=pLinkTable->pHead;
    while(p!=NULL)
    {    
        if(p==pNode)
            return p->pNext;
        p=p->pNext;
    }
    return NULL;
}
