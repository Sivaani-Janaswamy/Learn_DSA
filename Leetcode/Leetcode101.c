#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode{
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
}TreeNode;
struct TreeNode* traversal(struct TreeNode* root);
struct TreeNode* traversal(struct TreeNode* root){ 
    if(root->right == NULL || root->left == NULL){
       return root;
    }
    if(traversal(root->left)->val == traversal(root->right)->valn){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return NULL;
}

struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
/*    // Construct a symmetric tree:
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    3   4 4   3 */
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    
    traversal(root);
    
    return 0;
}
/*
bool isSymmetric(struct TreeNode* root) {
    
}*/