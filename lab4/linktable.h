/**************************************************************************************************/
/*Copyright: qcc                                                                                  */
/*Allrights reserved.                                                                             */
/*                                                                                                */
/*filename:     lab3                                                                              */
/*filelabel:                                                                                      */
/*LANGUAGE:     C                                                                                 */
/*TARGETENV:    ANY                                                                               */
/*AUTHER:       QCC                                                                               */
/*DATE:         2017.10.14                                                                        */
/*VERSION:      1.4                                                                               */
/*                                                                                                */
/*                                                                                                */
/**************************************************************************************************/

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#define SUCCESS 0
#define FAILURE (-1)

/*
 *LINK TABLE NODE Type
 */
typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;

/*
 *LINK table type
 */
typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int SumOfNode;
}tLinkTable;

tLinkTable * CreateLinkTable();
int DeleteLinkTable(tLinkTable *pLinkTable);
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);

#endif 
