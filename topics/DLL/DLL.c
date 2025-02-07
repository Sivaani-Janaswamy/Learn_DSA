#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *prev, *next;
} Node;

Node* head = NULL;

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
        free(newnode);
        return;
    }

    if (temp->next == NULL) {
        insertAtEnd(value);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;

    while (temp != NULL && temp->val != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp == head) head = temp->next;

    free(temp);
}

void traversal() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traversalReverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <- ", temp->val);
        temp = temp->prev;
    }
    printf("NULL\n");
}

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

void freeList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    int n, pos, ele;
    while (1) {
        printf("\n---------------------\n");
        printf(" 1. InsertAtFront\n 2. InsertAtEnd\n 3. InsertAtPos\n 4. DeleteNode\n 5. Traversal\n 6. Reverse Traversal\n 7. Search\n 8. Exit\n");
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
                printf("Enter Element to Delete: ");
                scanf("%d", &ele);
                deleteNode(ele);
                break;
            case 5:
                traversal();
                break;
            case 6:
                traversalReverse();
                break;
            case 7:
                printf("Enter Element: ");
                scanf("%d", &ele);
                printf("Element %s found\n", search(ele) ? "is" : "is not");
                break;
            case 8:
                freeList();
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
