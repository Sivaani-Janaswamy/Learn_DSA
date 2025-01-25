#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;
ListNode* head = NULL;
void traversal(ListNode* head);
void traversal(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
        printf("%d -> ",temp->val);
        temp = temp->next;
    }
    printf("NULL \n");
}
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;  
    struct ListNode* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->val == temp->next->val) {
            
            struct ListNode* duplicate = temp->next;
            temp->next = temp->next->next;  
            free(duplicate);  
        } else {
            temp = temp->next;
        }
    }
    return head;
}
int main() {
   ListNode* node1 = (ListNode*)malloc(sizeof(ListNode));
    if(node1 == NULL){
        printf("Memory Allocation Failed!");
    }
    ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
    if(node2 == NULL){
        printf("Memory Allocation Failed!");
    } 
    ListNode* node3 = (ListNode*)malloc(sizeof(ListNode));
    if(node3 == NULL){
        printf("Memory Allocation Failed!");
    }
    ListNode* node4 = (ListNode*)malloc(sizeof(ListNode));
    if(node3 == NULL){
        printf("Memory Allocation Failed!");
    }
    head = node1;
    node1->val = 1;
    node1->next = node2;
    node2->val = 1;
    node2->next = node3;
    node3->val = 1;
    node3->next = node4;
    node4->val = 1;
    node4->next = NULL;
    printf("Original List: \n");
    traversal(head);
    deleteDuplicates(head);
    traversal(head);
}
