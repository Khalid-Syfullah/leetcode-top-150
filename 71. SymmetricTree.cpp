#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool mirror(TreeNode* a, TreeNode* b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    return root == nullptr || mirror(root->left, root->right);
}

int main() {
    cout << boolalpha;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << isSymmetric(root) << "\n";

    TreeNode* r2 = new TreeNode(1);
    r2->left = new TreeNode(2);
    r2->right = new TreeNode(2);
    r2->left->right = new TreeNode(3);
    r2->right->right = new TreeNode(3);
    cout << isSymmetric(r2) << "\n";
    return 0;
}
