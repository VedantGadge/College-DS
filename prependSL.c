#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Prepend operation for Singly Linked List

struct Node{
    int data;
    struct Node* next;
};

void main(){
    struct Node* head = NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int n;
    printf("Enter the new node data: \n");
    scanf("%d",&n);
    newNode->data=n;

    if (head==NULL){
        head=newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = head;
        head=newNode;
    }

    printf("New node inserted with data: %d\n", head->data);
    free(newNode);
    getch();
}