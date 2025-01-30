#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000  // Define the number of buckets

typedef struct Node {
    int key, val;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[SIZE]; // Array of linked list heads
} MyHashMap;

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Create a new hash map
MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    for (int i = 0; i < SIZE; i++) {
        obj->buckets[i] = NULL;
    }
    return obj;
}

// Insert or update a key-value pair
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = hash(key);
    Node* temp = obj->buckets[index];
    
    while (temp) { 
        if (temp->key == key) { 
            temp->val = value; // Update existing key
            return;
        }
        temp = temp->next;
    }

    // Key not found, insert at head
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->val = value;
    newNode->next = obj->buckets[index];
    obj->buckets[index] = newNode;
}

// Retrieve a value
int myHashMapGet(MyHashMap* obj, int key) {
    int index = hash(key);
    Node* temp = obj->buckets[index];
    
    while (temp) {
        if (temp->key == key) return temp->val;
        temp = temp->next;
    }
    return -1; // Not found
}

// Remove a key
void myHashMapRemove(MyHashMap* obj, int key) {
    int index = hash(key);
    Node* temp = obj->buckets[index];
    Node* prev = NULL;
    
    while (temp) {
        if (temp->key == key) {
            if (prev) {
                prev->next = temp->next; // Remove from middle or end
            } else {
                obj->buckets[index] = temp->next; // Remove head
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Free the entire hash map
void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < SIZE; i++) {
        Node* temp = obj->buckets[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(obj);
}

/**
 * Example usage:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, 1, 10);
 * int param_2 = myHashMapGet(obj, 1);
 * myHashMapRemove(obj, 1);
 * myHashMapFree(obj);
 */
