#include <stdio.h>
#include "node.h"

int main() {

    struct Node *head, *newNode;
    int n, option;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d%f", &newNode->ID, &newNode->avg);
    newNode->next=NULL;
    head=newNode;

    createList(head, n-1);
    printList(head);

    while(option!=0){

         printf("\nOR 0 to end.\n");

         scanf("%d", &option);
         switch(option)
         {
             case 0: break;
             case 1: addFirst(&head);
             break;
             case 2: addLast(head);
             break;
             case 3: addPosition(head);
             break;
             case 4: printList(head);
             break;
             case 5: deleteAtEnd(head);
             break;
             case 6: deleteAtPosition(head);
             break;
             case 7: deleteAtFirst(&head);
             break;
             case 8: deleteList(head);
             head=NULL;
             break;
             default: printf("Wrong option");
             break;

         }
    }




    return 0;
}