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

/* Prints level order traversal in Java List<List<Integer>> format: [[3], [9, 20], [15, 7]] */
void levelOrder(struct TreeNode *root) {
    if (!root) {
        puts("[]");
        return;
    }
    struct TreeNode *q[1024];
    int head = 0, tail = 0;
    q[tail++] = root;
    putchar('[');
    int firstLevel = 1;
    while (head < tail) {
        int size = tail - head;
        if (!firstLevel) printf(", ");
        firstLevel = 0;
        putchar('[');
        for (int i = 0; i < size; ++i) {
            struct TreeNode *node = q[head++];
            if (i) printf(", ");
            printf("%d", node->val);
            if (node->left)  q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        putchar(']');
    }
    puts("]");
}

int main(void) {
    struct TreeNode *root = newNode(3);
    root->left  = newNode(9);
    root->right = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);

    levelOrder(root);   // [[3], [9, 20], [15, 7]]
    levelOrder(NULL);   // []
    return 0;
}
