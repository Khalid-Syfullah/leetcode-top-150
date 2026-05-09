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

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (!root || root == p || root == q) return root;
    struct TreeNode *left  = lowestCommonAncestor(root->left,  p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main(void) {
    struct TreeNode *root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left  = newNode(7);
    root->left->right->right = newNode(4);

    // lca1: LCA of node 5 and node 1 => 3
    struct TreeNode *lca1 = lowestCommonAncestor(root, root->left, root->right);
    // lca2: LCA of node 5 and node 4 => 5
    struct TreeNode *lca2 = lowestCommonAncestor(root, root->left, root->left->right->right);

    printf("%d\n", lca1->val);
    printf("%d\n", lca2->val);
    return 0;
}
