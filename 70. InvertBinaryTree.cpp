#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* l = invertTree(root->left);
    TreeNode* r = invertTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}

void inorder(TreeNode* n, string& sb) {
    if (n == nullptr) return;
    inorder(n->left, sb);
    sb += to_string(n->val) + " ";
    inorder(n->right, sb);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    invertTree(root);
    string sb;
    inorder(root, sb);
    while (!sb.empty() && sb.back() == ' ') sb.pop_back();
    cout << sb << "\n";
    return 0;
}
