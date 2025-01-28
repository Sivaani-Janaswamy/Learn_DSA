//LinkedList 
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {
     while(head!=NULL && head->val == val){ //important if next node value is also the one to remove 
        head = head->next;
     }
     struct ListNode* temp = head;
     while(temp != NULL && temp->next != NULL){
         if(temp->next->val == val)
         {  
            struct ListNode* toDelete = temp->next;
            temp->next = temp->next->next;     
            free(toDelete);
         }
         else{
         temp = temp->next;
         }
     }
     return head;
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = createNode(7);
    head->next = createNode(7);
    head->next->next = createNode(7);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(7);
    head->next->next->next->next->next = createNode(7);

    printf("Original List:\n");
    printList(head);

    head = removeElements(head, 7);

    printf("Updated List:\n");
    printList(head);

    return 0;
}
