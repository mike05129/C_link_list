#ifndef _Basic_Con_
#define _Basic_Con_

#include <stdio.h>
#include <stdlib.h>


#define basic_concept1 1 /*0:test basic func*/ 

typedef struct node
{
    int data;
    struct node *next;
    /* data */
}Node;

void FreeList(Node *node);
void PrintNode(Node *node);
void AddNode(Node **node , int value);

#endif