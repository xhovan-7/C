#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;

    struct Node *next;
}node;

void printList(node *head){
    node *temp = head;

    while(temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
}

node *createNewNode(int value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

node *insert_at_beginning(node **head, node *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}



int main(){
    node *head = NULL;
    node *temp;


    for(int i = 0; i < 25; i++){
        temp = createNewNode(i);
        head = insert_at_beginning(head, temp);
    }


    printList(head);

    return 0;
}