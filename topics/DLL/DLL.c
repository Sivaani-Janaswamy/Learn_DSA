#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Node structure
typedef struct Node {
    int val;
    struct Node *prev, *next;
} Node;

Node* head = NULL; // Global head pointer

// Function to create a new node
Node* create(int value) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->val = value;
    newnode->prev = newnode->next = NULL;
    return newnode;
}

// Insert at the front
void insertAtFront(int value) {
    Node* newnode = create(value);
    if (head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

// Insert at the end
void insertAtEnd(int value) {
    Node* newnode = create(value);
    if (head == NULL) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Insert at a specific position (1-based index)
void insertAtPos(int value, int pos) {
    if (pos <= 1) {
        insertAtFront(value);
        return;
    }
    Node* newnode = create(value);
    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newnode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Traversal function
void traversal() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search function
bool search(int ele) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == ele) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Free memory
void freeList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

// Main function
int main() {
    printf("Main Function\n")
    int n, pos, ele;
    while (1) {
        printf("\n---------------------\n");
        printf(" 1. InsertAtFront\n 2. InsertAtEnd\n 3. InsertAtPos\n 4. Traversal\n 5. Search\n 6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &ele);
                insertAtFront(ele);
                break;
            case 2:
                printf("Enter Element: ");
                scanf("%d", &ele);
                insertAtEnd(ele);
                break;
            case 3:
                printf("Enter Element: ");
                scanf("%d", &ele);
                printf("Enter Position: ");
                scanf("%d", &pos);
                insertAtPos(ele, pos);
                break;
            case 4:
                traversal();
                break;
            case 5:
                printf("Enter Element: ");
                scanf("%d", &ele);
                printf("Element %s found\n", search(ele) ? "is" : "is not");
                break;
            case 6:
                freeList();
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
