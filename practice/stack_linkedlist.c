#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
}Node;

Node* head = NULL;

Node* createnode(int val){
      Node* newnode = (Node*)malloc(sizeof(Node));
      newnode->data = val;
      newnode->prev = NULL;
      return newnode;
}

void push(int val){
     Node* newnode = createnode(val);
     newnode->prev = head;
     head = newnode;
}

void pop(){
   if(head == NULL){
    printf("List is empty. Nothing to pop!\n");
    return;
   }
   Node* temp = head;
   head = head->prev;
   free(temp);
}

void traversal(){
  if(head == NULL){
    printf("List is empty. Nothing to traverse!\n");
    return;
  }
  Node* temp = head;
  while(temp != NULL){
    printf(" %d -> ", temp->data);
    temp = temp->prev;
  }
  printf("NULL\n");
}

void peek(){
    if(head == NULL){
        printf("List is empty. Nothing to peek!\n");
        return;
      }
    printf("Top element: %d \n", head->data);
}

int main(){
    int ch, ele; 
    printf("Stacks with Linked Lists\n");
    printf("1. Push \n2. Pop \n3. Peek \n4. Traversal \n5. Exit \n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                traversal();
                break;
            case 5:
                printf("Exiting\n");
                return 0;
            default:printf("Invalid Input\n");
        }
    }
}
