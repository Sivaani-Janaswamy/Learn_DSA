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
int length(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
       len++;
       temp = temp->next;
    }
    return len;
}
int traversetoNode(Node* head, int mid){
    if(head==NULL){
        return 0;
    }
    int pos = 0;
    Node* temp = head;
    while(pos<mid && temp!=NULL){
        pos++;
        temp = temp->next;
    }
    if(temp==NULL){
        return -1;
    }
    return temp->data;
}
int binarysearch(Node* head, int key) {
    int low = 0;
    int high = length(head)-1;
    int mid = (low+high)/2;
    while(low<=high){
        if(traversetoNode(head,mid)==key){
            return mid;
        }
        else if(traversetoNode(head,mid)>key){
            high = mid-1;
            mid = (low+high)/2;
        }
        else{
            low = mid+1;
            mid = (low+high)/2;
        }
    }
    return -1;
}

int main() {
    printf("Binary Search using linked lists\n");

    Node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);

    traversal(head);

    int key;
    printf("Element to search: ");
    scanf("%d", &key);

    int position = binarysearch(head, key);
    if (position != -1) {
        printf("Element is found at position: %d\n", position);
    } else {
        printf("Element not found in the list.\n");
    }

    return 0;
}
