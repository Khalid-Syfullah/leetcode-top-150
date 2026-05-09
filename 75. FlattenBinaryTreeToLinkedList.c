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
    node->left = NULL;
    node->right = NULL;
    return node;
}

static struct TreeNode *prev;

static void reversePreorder(struct TreeNode *node) {
    if (node == NULL) return;
    reversePreorder(node->right);
    reversePreorder(node->left);
    node->right = prev;
    node->left = NULL;
    prev = node;
}

void flatten(struct TreeNode *root) {
    prev = NULL;
    reversePreorder(root);
}

static void printRightChain(struct TreeNode *root) {
    struct TreeNode *curr = root;
    while (curr != NULL) {
        printf("%d", curr->val);
        if (curr->right != NULL) printf(" -> ");
        curr = curr->right;
    }
    printf("\n");
}

int main(void) {
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);
    printRightChain(root);

    return 0;
}
