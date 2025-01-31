//floyd's cycle
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
 };
bool hasCycle(struct ListNode *head);
bool hasCycle(struct ListNode *head) { // this is the floyd's cycle with slow and fast pointers
     struct ListNode *slow = head;
     struct ListNode *fast = head;
     while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
     }
     return false;
}
//Now Creating Main Function to test the above


struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct ListNode *head = createNode(1);
    struct ListNode *second = createNode(2);
    struct ListNode *third = createNode(3);
    struct ListNode *fourth = createNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    if (hasCycle(head)) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}