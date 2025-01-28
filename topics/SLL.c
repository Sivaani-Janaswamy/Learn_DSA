//Singly Linked List 
#include <stdio.h>
#include <stdlib.h>
void insertAtFront(int ele);
void insertAtEnd(int ele);
void insertAtPos(int pos, int ele);
void deleteAtFront();
void deleteAtEnd();
void traversal();
int length();
int search(int ele);

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtFront(int ele){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL){
        printf("Memory Allocation Failed!");
    }
    newnode->data = ele;
    newnode->next = head;
    head = newnode;
}
void insertAtEnd(int ele){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL){
        printf("Memory Allocation Failed!");
        return;
    }
    newnode->data = ele;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        return;
    }
    else {
      Node* temp = head; //temporary variable for traversing list from the head pointing to the node
      while(temp->next!=NULL){ //temp->next instead of temp because temp variable shouldn't be null but temp->next pointer should null as it is temp holds the last node 
        temp = temp->next;
      }
      printf("\n");
      temp->next = newnode;
    }
}
void insertAtPos(int pos, int ele){
     Node* newnode = (Node*)malloc(sizeof(Node));
     Node* temp = head;
     newnode->data = ele;
     if(pos<1){
        printf("Position doesn't exist!\n");
     }
     else if(pos>length()){
        printf("Position doesn't exist!\n");
     }
     else{
        if(pos == 1)
       {
        temp = temp->next;
        head = newnode;
        newnode->next = temp;
       }
       else{
          int count=1;
          temp = head;
          while(count<pos-1 && temp!=NULL)
            {
             temp=temp->next;
             count++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
          }
       }
}
int length(){
    int count = 0;
    Node* temp = head;
    if(head==NULL){
        return 0;
    }
    else{
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
}
void deleteAtFront(){
    if(head==NULL){
        printf("Cannot Delete. List is empty\n");
    }
    else{
    head = head->next;
    }
}
void deleteAtEnd(){
    Node* temp = head;
    if(head==NULL){
        printf("Cannot Delete. List is empty\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("Cannot delete. List is empty.\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    Node* temp = head;

    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    int count = 1;

    while (count < pos && temp != NULL) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position doesn't exist.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}
void traversal(){
    int count = 0;
    Node* temp = head;
    if(head==NULL){
        printf("List is empty");
    }
    else{
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
            count++;
        }
        printf("NULL\n");
        printf("The number of elements present: %d\n",count);
    }
}

int search(int ele){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == ele){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main() {
    int n,pos;
    printf("-------------------\n");
    printf("Singly Linked List\n");
    int ele;
    while(1){
      printf("\n---------------------\n");
      printf(" 1.InsertAtFront\n 2.InsertAtEnd\n 3.InsertAtPos\n 4.DeleteAtFront\n 5.DeleteAtEnd\n 6.DeleteAtPos\n 7.Traversal\n 8.Searching \n 9.Exit\n");
      printf("Enter Choice:\n");
      scanf("%d",&n);
      switch(n)
      {
        case 1: printf("Enter Element:\n");
                scanf("%d",&ele);
                insertAtFront(ele); break;
        case 2: printf("Enter Element:\n");
                scanf("%d",&ele);
                insertAtEnd(ele); break;
        case 3: printf("Enter Element:\n");
                scanf("%d",&ele);
                printf("Enter Position:\n");
                scanf("%d",&pos);
                insertAtPos(pos,ele); break;
        case 4: deleteAtFront(); break;
        case 5: deleteAtEnd(); break;
        case 6: printf("Enter Position:\n");
                scanf("%d",&pos);
                deleteAtPos(pos); break;
        case 7: traversal(); break;
        case 8: printf("Enter Element:\n ");
                scanf("%d",&ele);
                printf("The element is present: %d\n",search(ele));
                break;
        case 9: return 0;
        default: printf("Invalid!\n");
       }
    }
    return 0;
}
// Front insertion
/*void create(int n) {
    for (int i = 0; i < n; i++) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter Data of Node %d:\n", i + 1);
        scanf("%d", &(newnode->data));
        newnode->next = head;
        head = newnode;
    }
}
*/
// Display the linked list
/*
void display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <- ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}*/


