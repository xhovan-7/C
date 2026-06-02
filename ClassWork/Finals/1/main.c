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


int main(){
    node n1, n2, n3;
    node *head;

    n1.value = 2;
    n2.value = 5;
    n3.value = 9;

    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    node n4;
    n4.value = 13;
    n2.next= &n4;
    n4.next = &n3;

    head = head->next;

    printList(head);

    return 0;
}