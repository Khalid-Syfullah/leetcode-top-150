#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* prevNode;

void reversePreorder(TreeNode* node) {
    if (node == nullptr) return;
    reversePreorder(node->right);
    reversePreorder(node->left);
    node->right = prevNode;
    node->left = nullptr;
    prevNode = node;
}

void flatten(TreeNode* root) {
    prevNode = nullptr;
    reversePreorder(root);
}

void printRightChain(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->right != nullptr) cout << " -> ";
        curr = curr->right;
    }
    cout << "\n";
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    printRightChain(root);
    return 0;
}
