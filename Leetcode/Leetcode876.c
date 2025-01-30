#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow; 
}