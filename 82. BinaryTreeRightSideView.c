#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode {
    struct TreeNode *node;
    int level;
};

struct TreeNode *newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void rightSideView(struct TreeNode *root) {
    if (!root) return;
    struct QueueNode q[1024];
    int head = 0, tail = 0;
    q[tail++] = (struct QueueNode){root, 0};
    int currentLevel = -1;
    while (head < tail) {
        int size = tail - head;
        for (int i = 0; i < size; ++i) {
            struct TreeNode *node = q[head].node;
            currentLevel = q[head].level;
            ++head;
            if (node->left) q[tail++] = (struct QueueNode){node->left, currentLevel + 1};
            if (node->right) q[tail++] = (struct QueueNode){node->right, currentLevel + 1};
            if (i == size - 1) printf("%d ", node->val);
        }
    }
    puts("");
}

int main(void) {
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    rightSideView(root);
    return 0;
}
