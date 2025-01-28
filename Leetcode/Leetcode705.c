#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyHashSet {
    int val;
    struct MyHashSet* next;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* newSet = (MyHashSet*)malloc(sizeof(MyHashSet));
    newSet->val = -1;
    newSet->next = NULL;
    return newSet;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    MyHashSet* temp = obj;
    while (temp->next != NULL) {
        if (temp->next->val == key) {
            return;
        }
        temp = temp->next;
    }
    MyHashSet* newNode = (MyHashSet*)malloc(sizeof(MyHashSet));
    newNode->val = key;
    newNode->next = NULL;
    temp->next = newNode;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    MyHashSet* temp = obj;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->val == key) {
            MyHashSet* toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    MyHashSet* temp = obj;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
        if (temp->val == key) {
            return true;
        }
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    MyHashSet* temp = obj;
    while (temp != NULL) {
        MyHashSet* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
}

int main() {
    MyHashSet* obj = myHashSetCreate();
    myHashSetAdd(obj, 1);
    myHashSetAdd(obj, 2);
    myHashSetAdd(obj, 3);
    printf("%d\n", myHashSetContains(obj, 2));
    myHashSetRemove(obj, 2);
    printf("%d\n", myHashSetContains(obj, 2));
    myHashSetFree(obj);
    return 0;
}
