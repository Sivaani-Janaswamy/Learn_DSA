#include<stdio.h>
#include<stdlib.h>
struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL){
     return NULL;
    }
    struct ListNode *tempA = headA;
    struct ListNode *tempB = headB;
    while(tempA != tempB){
        tempA = (tempA==NULL)?headB:tempA->next;
        tempB = (tempB==NULL)?headA:tempB->next;

    }
    return tempA;
}struct ListNode *newNode(int value) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

// Example usage
int main() {
    struct ListNode *common = newNode(8);
    common->next = newNode(10);
    
    struct ListNode *headA = newNode(3);
    headA->next = newNode(6);
    headA->next->next = newNode(9);
    headA->next->next->next = common;
    
    struct ListNode *headB = newNode(4);
    headB->next = newNode(5);
    headB->next->next = common;

    struct ListNode *intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL) {
        printf("Intersection node value: %d\n", intersection->val);
    } else {
        printf("No intersection found\n");
    }

    return 0;
}