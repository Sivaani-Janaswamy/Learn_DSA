#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* createnode(int val){
      Node* newnode = (Node*)malloc(sizeof(Node));
      newnode->data = val;
      newnode->next = NULL;
      return newnode;
}
void push(Node* head,int val){
     if(head==NULL){
        head = createnode(val);
     }
     else{
         Node* temp = head;
         
     }
}