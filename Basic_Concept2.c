/*Basic on Basic_Concept, Packed into function*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Basic_Concept2.h"

int main(int argc, char *argn[])
{
#if basic_concept1 == 0
    /*Add a simple number here*/
    /*5*/
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 5;
    head->next = NULL;

    /*Add Second number here(Second node)*/
    /*5->13*/
    Node *head2 = (Node *)malloc(sizeof(Node));
    head2->data = 13;
    head->next = head2;
    head2->next = NULL;

    /*Add Third number here (Third node)*/
    /*5->13->24*/
    Node *head3 = (Node *)malloc(sizeof(Node));
    head3->data = 24;
    head2->next = head3;
    head3->next = NULL;

#elif basic_concept1 == 1

    Node *head = NULL;
    AddNode(&head, 5);
    AddNode(&head, 13);
    AddNode(&head, 13);
    AddNode(&head, 24);
    DeleteNode(&head, 1);
    InsertNode(&head, 17, 13);
    PrintNode(head);
    FreeList(head);
#endif
    return 0;
}

void PrintNode(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void AddNode(Node **node, int value)
{
    /* using **node to change first head */
    Node *New_Node = (Node *)malloc(sizeof(Node));
    New_Node->data = value;
    New_Node->next = NULL;

    /*Checking it's the first node?*/
    if (*node == NULL)
    {
        *node = New_Node;
        return;
    }
    else
    {
        /*Using for find header last position*/
        Node *current;
        current = *node;
        /*Finding the last Node*/
        while (current->next != NULL)
        {
            current = current->next;
        }
        /*Add after the last Node*/
        current->next = New_Node;
        return;

        /*Wrong Use!!! It changes the head pointer position
        while ((*node)->next != NULL)
        {
            (*node) =(*node)->next;
        }
        (*node)->next = New_Node;**/
    }
}

void InsertNode(Node **node, int value, int insert_after_value)
{
    Node *insert = (Node *)malloc(sizeof(Node));
    Node *current = *node;
    bool find_value = false;
    while (current != NULL)
    {
        if (current->data == insert_after_value)
        {
            find_value = true;
            insert->data = value;
            insert->next = NULL;
            /*Check node is the lastest*/
            if (current->next == NULL)
            {
                current->next = insert;
                break;
            }
            else
            {
                insert->next = current->next;
                current->next = insert;
                break;
            }
        }
        /*Check next node*/
        current = current->next;
    }
    if (find_value == false)
    {
        printf("Can't find value:%d \n", insert_after_value);
    }
}

void DeleteNode(Node **node, int delete_value)
{
    Node *temp = NULL;
    Node *current = *node;
    //bool find_value = false;

    if (current->data == delete_value)
    {
        *node = current->next;
        free(current);
        return;
    }

    while (current != NULL)
    {
        if (current->next->data == delete_value)
        {
            //find_value = true;
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    /*while ((current != NULL) && (current->data != delete_value))
    {
        temp = current;
        current = current->next;
    }
    if (temp == NULL)
    {
        printf("Not found. \n");
    }
    else
    {
        temp->next = current->next;
        free(temp);
    }*/

    /*if (find_value == false)
    {
        printf("Can't find value:%d \n", delete_value);
        free(temp);
    }*/
}

void FreeList(Node *node)
{
    Node *current, *temp;
    current = node;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}
