#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Function to create a new tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Main function to test the isSameTree function
int main() {
    // Creating first tree
    TreeNode* root1 = createNode(1);
    root1->left = createNode(4);
    root1->right = createNode(3);

    // Creating second tree
    TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);

    // Check if both trees are the same
    if (isSameTree(root1, root2)) {
        printf("Both trees are the same.\n");
    } else {
        printf("The trees are different.\n");
    }

    // Free allocated memory
    free(root1->left);
    free(root1->right);
    free(root1);
    free(root2->left);
    free(root2->right);
    free(root2);

    return 0;
}
