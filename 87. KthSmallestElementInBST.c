#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* Iterative inorder using an explicit stack */
int kthSmallest(struct TreeNode *root, int k) {
    struct TreeNode *stack[1024];
    int top = 0;
    struct TreeNode *current = root;

    while (current != NULL || top > 0) {
        while (current != NULL) {
            stack[top++] = current;
            current = current->left;
        }
        current = stack[--top];
        k--;
        if (k == 0) return current->val;
        current = current->right;
    }
    return -1;
}

void freeTree(struct TreeNode *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct TreeNode *root1 = newNode(3);
    root1->left  = newNode(1);
    root1->right = newNode(4);
    root1->left->right = newNode(2);

    struct TreeNode *root2 = newNode(5);
    root2->left  = newNode(3);
    root2->right = newNode(6);
    root2->left->left  = newNode(2);
    root2->left->right = newNode(4);
    root2->left->left->left = newNode(1);

    printf("%d\n", kthSmallest(root1, 1));
    printf("%d\n", kthSmallest(root2, 3));

    freeTree(root1);
    freeTree(root2);
    return 0;
}
