#include "LinkedList.h"




Node* CreateNode(){
    Node* new_node = malloc(sizeof(struct Node));
    if(new_node == NULL){
        printf("Error, couldn't allocate memory");
        return NULL;
    }

    new_node -> data = NULL;
    new_node -> next = NULL;

    return new_node;
}


Node* InsertNode(Node** head_ref, void* new_data)
{
    /* Allocate node*/ 
    Node* new_node = CreateNode();

    /*put in the data*/
    new_node->data  = new_data;

    /*Make next of new node as head*/
    new_node->next = (*head_ref);

    /*move the head to point to the new node*/

    (*head_ref)  = new_node;
    return new_node;
}



void *SearchNode(Node* head, void *data, int(*cmp_func)(void*, void*)){
    while(head!= NULL)
    {
        if(cmp_func(data,head -> data) == 0)
            return head->data;

        head = head -> next;
    }

    return NULL;
}



