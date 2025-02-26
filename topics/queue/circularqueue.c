#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue (Insert element)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Dequeue (Remove element)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted %d from front\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Reset when last element is removed
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
