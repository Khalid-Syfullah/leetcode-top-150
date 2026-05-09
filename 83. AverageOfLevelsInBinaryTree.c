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

/* Prints averages of each level in Java List format, e.g. [3.0, 14.5, 11.0] */
void averageOfLevels(struct TreeNode *root) {
    if (!root) {
        puts("[]");
        return;
    }
    struct TreeNode *q[1024];
    int head = 0, tail = 0;
    q[tail++] = root;
    double results[1024];
    int numLevels = 0;
    while (head < tail) {
        int size = tail - head;
        long long sum = 0;
        for (int i = 0; i < size; ++i) {
            struct TreeNode *node = q[head++];
            sum += node->val;
            if (node->left)  q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
        }
        results[numLevels++] = (double)sum / size;
    }
    putchar('[');
    for (int i = 0; i < numLevels; ++i) {
        if (i) printf(", ");
        printf("%.1f", results[i]);
    }
    puts("]");
}

int main(void) {
    struct TreeNode *root = newNode(3);
    root->left  = newNode(9);
    root->right = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);
    averageOfLevels(root); // [3.0, 14.5, 11.0]
    return 0;
}
