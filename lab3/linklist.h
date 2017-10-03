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

typedef struct DataNode
{
    char *cmd;
    char *desc;
    int (*handler)();
    struct DataNode *next;
}tDataNode;

tDataNode *FindCMD(tDataNode *head, char *cmd);

int ShowAllCMDs(tDataNode *head); 
