#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode { 
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head) {
    struct ListNode* temp = head;
    int n = 0;
    while(temp != NULL) {
        temp = temp->next;
        n++;
    }
    temp = head;
    int sum = 0;
    while(temp != NULL) {
        sum = sum + (temp->val * (int)pow(2, n - 1));  // Cast pow(2, n - 1) to int
        n = n - 1;
        temp = temp->next;
    }
    return sum;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(0);
    head->next->next = createNode(1);
    
    printf("Linked List: ");
    printList(head);
    
    int decimalValue = getDecimalValue(head);
    printf("Decimal Value: %d\n", decimalValue);
    
    struct ListNode* temp = head;
    while(temp != NULL) {
        struct ListNode* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    
    return 0;
}
