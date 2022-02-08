#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    /* data */
}Node;

void PrintNode(Node *node){
    while (node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");    
}


int main(int argc , char* argn[]){
    /*Add a simple number here*/
    /*5*/
    Node *head = (Node*)malloc(sizeof(Node));
    (*head).data = 5;//same with head->date = 5
    head->next = NULL;

    /*Add Second number here(Second node)*/
    /*5->13*/
    Node *head2 = (Node*)malloc(sizeof(Node));
    head2->data = 13;
    head->next = head2;
    head2->next = NULL;

    /*Add Third number here (Third node)*/
    /*5->13->24*/
    Node *head3 = (Node*)malloc(sizeof(Node));
    head3->data = 24;
    head2->next = head3;
    head3->next = NULL;

    PrintNode(head);

    return 0;
}

