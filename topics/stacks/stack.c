#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAX = 10;
bool isFull(int top){
    if(top == MAX){
       return true;
    }
    return false;
}
bool isEmpty(int top){
    if(top == -1){
        return true;
    }
    return false;
}
void push(int *top, int stacks[], int ele){
    if(isFull){
        printf("Stack is Full! Cannot Insert.");
        return;
    }
}
