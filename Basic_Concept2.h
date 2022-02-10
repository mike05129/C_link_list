#ifndef _Basic_Con_
#define _Basic_Con_

#include <stdio.h>
#include <stdlib.h>


#define basic_concept1 1 /*0:Test basic concept 1*/ 

typedef struct node
{
    int data;
    struct node *next;
    /* data */
}Node;

void FreeList(Node *node);
void PrintNode(Node *node);
void AddNode(Node **node , int value);
void InsertNode(Node **node, int value, int insert_after_value);
void DeleteNode(Node **node,int delete_value);

#endif