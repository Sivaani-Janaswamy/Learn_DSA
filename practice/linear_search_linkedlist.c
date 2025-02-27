#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createnode(int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode; 
}

void traversal(Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int linearsearch(Node* head, int key) {
    Node* temp = head;
    int pos = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1; 
}

int main() {
    printf("Linear Search using linked lists\n");

    Node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(8);
    head->next->next->next = createnode(5);
    head->next->next->next->next = createnode(4);

    traversal(head);

    int key;
    printf("Element to search: ");
    scanf("%d", &key);

    int position = linearsearch(head, key);
    if (position != -1) {
        printf("Element is found at position: %d\n", position);
    } else {
        printf("Element not found in the list.\n");
    }

    return 0;
}
