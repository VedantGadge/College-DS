#include <stdio.h>
#include <stdlib.h>

// Prepend , append , insert after then insert before node operation for Singly Linked List

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void printList() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

void prependNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("New node prepended with data: %d\n", newNode->data);
}

void appendNode( int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("New node appended with data: %d\n", newNode->data);
}

void insertNodeAF(int data,int target){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->data != target) {
            temp = temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    printf("New node appended with data: %d\n", newNode->data);

}

void insertNodeBF( int data,int target){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        struct Node* pre = NULL;
        while (temp->data != target) {
            pre=temp;
            temp = temp->next;
        }
        newNode->next=temp;
        pre->next=newNode;
    }
    printf("New node appended with data: %d\n", newNode->data);

}  

void deleteLastNode() {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    
    if (head->next == NULL) { // If only one node is present
        free(head);
        head = NULL;
        printf("Last node deleted, the list is now empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;  
    free(temp);         
    printf("Last node deleted successfully.\n");
}

void deleteFirstNode() {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    
    if (head->next == NULL) { // If only one node is present
        free(head);
        head = NULL;
        printf("Last node deleted, the list is now empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;   
    free(temp);  
    printf("First node deleted successfully.\n");
}

void deleteNode(int target) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    
    if (head->next == NULL) { // If only one node is present
        free(head);
        head = NULL;
        printf("Last node deleted, the list is now empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != target) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node of data %d has been deleted! \n",target);

}

void deleteNodeBF(int target) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    
    if (head->next == NULL) { // If only one node is present
        free(head);
        head = NULL;
        printf("Last node deleted, the list is now empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next->data != target) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(prev);
    printf("Node of data %d has been deleted! \n",target);
}

void main(){
    
    int n,target,choice;
    int cont=1;
    printList();
    
    while(cont==1){
        printf("What u wanna do with the linked list\n");
        printf("Enter 1 to prepend in the Linked List\n");
        printf("Enter 2 to append in the Linked List\n");
        printf("Enter 3 to insert before a node in the Linked List\n");
        printf("Enter 4 to insert after a node in the Linked List\n");
        printf("Enter 5 to delete the last node in the Linked List\n");
        printf("Enter 6 to delete the first node in the Linked List\n");
        printf("Enter 7 to delete a node in the Linked List\n");
        printf("Enter 8 to delete after a node  in the Linked List\n");
        printf("Enter 9 to delete before a node in the Linked List\n");
        printf("Enter 10 to terminate operations\n");
        scanf("%d", &choice);
    
        switch (choice)
        {
        case 1:
            // Prepend
            printf("Enter the new node data to prepend: \n");
            scanf("%d", &n);
            prependNode(n);
            printList();
            break;
        
        case 2:
            // Append
            printf("Enter the new node data to append: \n");
            scanf("%d", &n);
            appendNode(n);
            printList();
            break;
    
        case 3:
            // Insert BF
            printf("Enter the new node data to insert: \n");
            scanf("%d", &n);
            printf("Enter the target node data: \n");
            scanf("%d", &target);
            insertNodeBF(n, target);
            printList();
            break;
    
        case 4:
            // Insert AF
            printf("Enter the new node data to insert: \n");
            scanf("%d", &n);
            printf("Enter the target node data: \n");
            scanf("%d", &target);
            insertNodeAF(n, target);
            printList();
            break;

        case 5:
             // Delete the last node
             deleteLastNode();
             printList();
             break;

        case 6:
             // Delete the first node
             deleteFirstNode();
             printList();
             break;

        case 7:
             // Delete specific node
             printf("Enter the target node data to delete : \n");
             scanf("%d", &target);
             deleteNode(target);
             printList();
             break;

        case 8:
             // Delete after node
             printf("Enter the target node data to delete : \n");
             scanf("%d", &target);
            //  deleteNode(target);
             printList();
             break;

        case 9:
             // Delete before node
            printf("Enter the target node data to delete before: \n");
            scanf("%d", &target);
            deleteNodeBF(target);
            printList();
            break;

        case 10:
            // Close Menu
            printList();
            printf("Terminating...\n");
            cont=0;
            break;

        default:
            printf("Enter a valid option!! \n");
            break;
        }
    
    }
}