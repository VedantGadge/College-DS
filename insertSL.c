#include <stdio.h>
#include <stdlib.h>

// Prepend , append then insert after node operation for Singly Linked List

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void prependNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("New node prepended with data: %d\n", newNode->data);
}

void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("New node appended with data: %d\n", newNode->data);
}

void insertNode(struct Node** head, int data,int target){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->data != target) {
            temp = temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    printf("New node appended with data: %d\n", newNode->data);

}

void main(){
    struct Node* head = NULL;
    int n;
    int target;

    // Prepend
    printf("Enter the new node data to prepend: \n");
    scanf("%d", &n);
    prependNode(&head, n);

    // Append
    printf("Enter the new node data to append: \n");
    scanf("%d", &n);
    appendNode(&head, n);

    // Insert
    printf("Enter the new node data to insert: \n");
    scanf("%d", &n);
    printf("Enter the target node data: \n");
    scanf("%d", &target);
    insertNode(&head,n, target);

    printList(head);
}