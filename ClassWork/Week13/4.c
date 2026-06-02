#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    char name[16];
    double avg;

    struct Node *next;
}Node;

Node *createNode(Node *prev){
    Node *newNode = malloc(sizeof(Node));
    newNode->next=NULL;
    if (prev != NULL){
        prev->next=newNode;
    }
        return newNode;
}

void createList(Node **head, int size){
    Node *temp = createNode(NULL);
    *head = createNode(temp);
    temp = *head;

    for(int i = 0; i < size; i++){
        temp = createNode(temp);
        scanf("%d &15s %lf", &temp->id, &temp->name, &temp->avg);
    }
}



int main(){
    int size;
    
    printf("Enter size: ");
    scanf("%d", &size);

    Node *head, *temp = malloc(sizeof(Node));



    return 0;
}