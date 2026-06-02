#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node{
   int ID;
   float avg;

   struct Node *next;
};

void createList(struct Node *temp, int n)
{
    struct Node *newNode;

    for(int i=0; i<n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d%f", &newNode->ID, &newNode->avg);
        newNode->next=NULL;

        temp->next=newNode;
        temp=newNode;
    }
}


void printList(struct Node *temp)
{
    while(temp!=NULL)
    {
        printf("\nID: %d Avg: %f", temp->ID, temp->avg);
        temp=temp->next;
    }
}

void addLast(struct Node *temp)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d%f", &newNode->ID, &newNode->avg);
    newNode->next=NULL;

     while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
}

void addFirst(struct Node **temp)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d%f", &newNode->ID, &newNode->avg);
    newNode->next=NULL;

    //without taking into consideration if it exists
    newNode->next=*temp;
    *temp=newNode;
}

void addPosition(struct Node *head)
{
    struct Node *newNode;
    int pos;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d%f", &newNode->ID, &newNode->avg);
    newNode->next=NULL;

    //without taking into consideration if it exists
    printf("Enter position: ");
    scanf("%d", &pos);

    for(int i=0; i<pos-1; i++)
    {
        head=head->next;
    }

    newNode->next=head->next;
    head->next=newNode;

}


void deleteAtEnd(struct Node *temp)
{
    while(temp->next->next!=NULL)
        temp=temp->next;

    struct Node *toDelete = temp->next;
    temp->next=NULL;
    free(toDelete);
}

void deleteAtFirst(struct Node **head)
{
    struct Node *temp = *head;
    *head=(*head)->next;
    free(temp);
}

void deleteAtPosition(struct Node *temp)
{
    int pos;
     //without taking into cons if it exists
    printf("Enter position: ");
    scanf("%d", &pos);

     for(int i=0; i<pos-1; i++)
    {
        temp=temp->next;
    }

     struct Node *toDelete = temp->next;
    temp->next=temp->next->next;
    free(toDelete);
}

void deleteList(struct Node *head)
{
    struct Node *temp;
    while(head!=NULL)
    {
       temp=head->next;
       free(head);
       head=temp;
    }
}