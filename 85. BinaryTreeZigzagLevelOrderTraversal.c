#include <stdbool.h>
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

void zigzagLevelOrder(struct TreeNode *root) {
    struct TreeNode *q[1024];
    int head = 0, tail = 0;
    bool leftToRight = true;
    q[tail++] = root;
    while (head < tail) {
        int size = tail - head;
        int vals[1024];
        for (int i = 0; i < size; ++i) {
            struct TreeNode *node = q[head++];
            int idx = leftToRight ? i : size - 1 - i;
            vals[idx] = node->val;
            if (node->left) q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        putchar('[');
        for (int i = 0; i < size; ++i) {
            if (i) printf(", ");
            printf("%d", vals[i]);
        }
        puts("]");
        leftToRight = !leftToRight;
    }
}

int main(void) {
    struct TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    zigzagLevelOrder(root);
    return 0;
}
