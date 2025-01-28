#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    int n = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    temp = head;
    int arr[n / 2];
    for (int i = 0; i < n / 2; i++) {
        arr[i] = temp->val;
        temp = temp->next;
    }

    if (n % 2 != 0) {
        temp = temp->next;
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        if (arr[i] != temp->val) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
void appendNode(struct ListNode** head, int val) {
    struct ListNode* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct ListNode* head = NULL;

    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 2);
    appendNode(&head, 1);

    printf("Linked List: ");
    printList(head);

    // Check if it's a palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
/*


   bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Step 1: Find the middle of the list using slow and fast pointers
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    struct ListNode* secondHalfStart = reverseList(slow);

    // Step 3: Compare the first and second halves
    struct ListNode* firstHalfStart = head;
    struct ListNode* secondHalfCopy = secondHalfStart; // To restore the list later
    bool isPalin = true;
    while (secondHalfStart != NULL) {
        if (firstHalfStart->val != secondHalfStart->val) {
            isPalin = false;
            break;
        }
        firstHalfStart = firstHalfStart->next;
        secondHalfStart = secondHalfStart->next;
    }

    // Step 4: Restore the second half (optional)
    reverseList(secondHalfCopy);

    return isPalin;
}


}*/