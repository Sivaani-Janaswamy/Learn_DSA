#include<stdio.h>
#include<stdlib.h>
// Linked List can be reversed iteratively and recursively 
struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;
struct ListNode* reverseList(struct ListNode* head) {
      struct ListNode* prev = NULL;
      struct ListNode* curr = head;
      struct ListNode* nxt;
      while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
      }
      return prev;
}
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from an array
struct ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    int values[] = {1, 2, 3, 4, 5};
    int size = sizeof(values) / sizeof(values[0]);
    
    struct ListNode* head = createLinkedList(values, size);
    
    printf("Original List: ");
    printLinkedList(head);
    
    // Call your reverseList function here
    head = reverseList(head);
    
    printf("Reversed List: ");
    printLinkedList(head);
    
    return 0;
}