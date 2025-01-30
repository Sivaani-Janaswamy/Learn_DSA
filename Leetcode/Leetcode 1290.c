#include<stdlib.h>
#include<stdio.h>
struct ListNode { 
     int val;
     struct ListNode *next;
};
#include <math.h>
int getDecimalValue(struct ListNode* head) {
    struct ListNode* temp = head;
   int  n = 0;
    while(temp!=NULL){
        temp=temp->next;
         n++;
    }
    temp = head;
    int sum = 0;
    while(temp!=NULL){
        sum = sum + (temp->val*pow(2,n-1));
        n = n-1;
        temp=temp->next;
    }
    return sum;
}