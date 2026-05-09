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

/* Prints the right-side view of a tree in Java List format, e.g. [1, 3, 4] */
void rightSideView(struct TreeNode *root) {
    if (!root) {
        puts("[]");
        return;
    }
    struct TreeNode *q[1024];
    int head = 0, tail = 0;
    q[tail++] = root;
    int result[1024];
    int resultSize = 0;
    while (head < tail) {
        int size = tail - head;
        for (int i = 0; i < size; ++i) {
            struct TreeNode *node = q[head++];
            if (node->left)  q[tail++] = node->left;
            if (node->right) q[tail++] = node->right;
            if (i == size - 1) result[resultSize++] = node->val;
        }
    }
    putchar('[');
    for (int i = 0; i < resultSize; ++i) {
        if (i) printf(", ");
        printf("%d", result[i]);
    }
    puts("]");
}

int main(void) {
    // Test 1: [1,2,3,null,5,null,4] -> [1, 3, 4]
    struct TreeNode *root1 = newNode(1);
    root1->left  = newNode(2);
    root1->right = newNode(3);
    root1->left->right  = newNode(5);
    root1->right->right = newNode(4);
    rightSideView(root1);

    // Test 2: [1,null,3] -> [1, 3]
    struct TreeNode *root2 = newNode(1);
    root2->right = newNode(3);
    rightSideView(root2);

    // Test 3: null -> []
    rightSideView(NULL);
    return 0;
}
