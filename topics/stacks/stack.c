#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

bool isFull(int* top) {
    return *top == MAX - 1;
}

bool isEmpty(int* top) {
    return *top == -1;
}

void push(int *top, int stacks[], int ele) {
    if (isFull(top)) {
        printf("Stack is Full! Cannot Push.\n");
        return;
    }
    stacks[++(*top)] = ele;
}

int pop(int *top, int stack[]) {
    if (isEmpty(top)) {
        printf("Stack is empty! Cannot Pop\n");
        return -1;
    }
    return stack[(*top)--];
}

int peek(int* top, int stack[]) {
    if (isEmpty(top)) {
        printf("Stack is Empty! Cannot Peek\n");
        return -1;
    }
    return stack[*top];
}
void display(int *top, int stack[]) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= *top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main() {
    int stacks[MAX];
    int top = -1;
    int ch = 0;
    int ele = 0;

    printf("Stacks\n");
    printf("1. Push \n2. Pop \n3. Peek \n4. isEmpty \n5. isFull \n6. Display \n7. Exit \n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &ele);
                push(&top, stacks, ele);
                break;
            case 2:
                printf("Popped: %d\n", pop(&top, stacks));
                break;
            case 3:
                printf("Top Element: %d\n", peek(&top, stacks));
                break;
            case 4:
                printf(isEmpty(&top) ? "Stack is Empty\n" : "Stack is Not Empty\n");
                break;
            case 5:
                printf(isFull(&top) ? "Stack is Full\n" : "Stack is Not Full\n");
                break;
            case 6:
                display(&top,stacks);
                break;
            case 7:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid Input\n");
        }
    }
}
