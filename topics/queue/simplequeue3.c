#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 5

typedef struct Queue {
    int arr[max];
    int front;
    int rear;
} Queue;

void initQ(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

int isFull(Queue* q) {
    return q->rear == max - 1;
}

void enqueueRear(Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert at rear.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Initialize front on first insert
    }
    q->arr[++q->rear] = val;
}

void enqueueFront(Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert at front.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0; // Initialize both for the first element
    } else if (q->front > 0) {
        q->arr[--q->front] = val;
    } else {
        printf("Cannot insert at front, no space available!\n");
    }
}

void dequeueFront(Queue* q) {
    if (isEmpty(q)) {
        printf("Cannot delete. Queue is empty.\n");
        return;
    }
    printf("Deleted from Front: %d\n", q->arr[q->front]);
    if (q->front == q->rear) {
        initQ(q); // Reset queue when last element is deleted
    } else {
        q->front++;
    }
}

void peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek!\n");
        return;
    }
    printf("Front: %d\n", q->arr[q->front]);
}

void rear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot rear!\n");
        return;
    }
    printf("Rear: %d\n", q->arr[q->rear]);
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot display!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQ(&q);
    int ch = 0, val;

    while (true) {
        printf("\nOutput Restricted Queue\n");
        printf("1. Enqueue at Rear\n2. Enqueue at Front\n3. Dequeue \n4. isFull\n5. isEmpty\n6. Peek\n7. Rear\n8. Display\n9. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueueRear(&q, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueueFront(&q, val);
                break;
            case 3:
                dequeueFront(&q);
                break;
            case 4:
                printf("Is Full: %d\n", isFull(&q));
                break;
            case 5:
                printf("Is Empty: %d\n", isEmpty(&q));
                break;
            case 6:
                peek(&q);
                break;
            case 7:
                rear(&q);
                break;
            case 8:
                display(&q);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid Choice. Enter Again\n");
        }
    }
    return 0;
}
