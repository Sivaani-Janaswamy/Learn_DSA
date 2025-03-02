#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* rear = NULL; // New rear pointer

// Create a new node
Node* createnode(int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

// Enqueue (Insert at the rear)
void enqueue(int val) {
    Node* newnode = createnode(val);
    if (head == NULL) { // If the queue is empty
        head = rear = newnode;
    } else {
        rear->next = newnode; // Link new node
        rear = newnode;       // Update rear pointer
    }
}

// Dequeue (Remove from the front)
void dequeue() {
    if (head == NULL) {
        printf("Queue is empty. Nothing to dequeue!\n");
        return;
    }
    Node* temp = head;
    printf("Dequeued: %d\n", temp->data);
    head = head->next;
    free(temp);

    // If the queue becomes empty, reset rear pointer
    if (head == NULL) {
        rear = NULL;
    }
}

// Peek (Front element)
void peek() {
    if (head == NULL) {
        printf("Queue is empty. Nothing to peek!\n");
        return;
    }
    printf("Front element: %d\n", head->data);
}

// Traverse the queue
void traversal() {
    if (head == NULL) {
        printf("Queue is empty. Nothing to traverse!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free the entire queue
void freeQueue() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int ch, ele;
    printf("Optimized Queue with Linked Lists\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Traversal\n5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                traversal();
                break;
            case 5:
                printf("Exiting and cleaning up...\n");
                freeQueue();
                return 0;
            default:
                printf("Invalid input\n");
        }
    }
}
