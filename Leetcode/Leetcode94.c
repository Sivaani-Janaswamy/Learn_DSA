#include <stdlib.h>
#include <stdio.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to count nodes in the tree
int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper function for inorder traversal
void inorderHelper(struct TreeNode* root, int* result, int* index) {
    if (!root) return;
    inorderHelper(root->left, result, index);
    result[(*index)++] = root->val;
    inorderHelper(root->right, result, index);
}

// Main function for inorder traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int index = 0;
    inorderHelper(root, result, &index);
    return result;
}

// Function to print the result array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n2 = {2, &n1, &n3};
    struct TreeNode n5 = {5, NULL, NULL};
    struct TreeNode root = {4, &n2, &n5};

    int returnSize;
    int* result = inorderTraversal(&root, &returnSize);
    
    printArray(result, returnSize);

    free(result);  // Free allocated memory
    return 0;
}
