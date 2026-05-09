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

struct TreeNode *invertTree(struct TreeNode *root) {
    if (root == NULL) return NULL;
    struct TreeNode *l = invertTree(root->left);
    struct TreeNode *r = invertTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}

static void inorder(struct TreeNode *n, char *buf, int *pos) {
    if (n == NULL) return;
    inorder(n->left, buf, pos);
    *pos += sprintf(buf + *pos, "%d ", n->val);
    inorder(n->right, buf, pos);
}

int main(void) {
    struct TreeNode *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
    invertTree(root);

    char buf[256];
    int pos = 0;
    inorder(root, buf, &pos);
    /* Remove trailing space */
    if (pos > 0 && buf[pos - 1] == ' ') buf[pos - 1] = '\0';
    printf("%s\n", buf); /* 9 7 6 4 3 2 1 */

    return 0;
}
