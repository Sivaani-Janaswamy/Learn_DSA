#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Check if deque is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
}

// Insert at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

// Display the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);
    display();

    deleteFront();
    display();

    deleteRear();
    display();

    insertRear(30);
    insertFront(15);
    display();

    return 0;
}
