#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode* node, int current) {
    if (node == nullptr) {
        return 0;
    }
    int value = current * 10 + node->val;
    if (node->left == nullptr && node->right == nullptr) {
        return value;
    }
    return dfs(node->left, value) + dfs(node->right, value);
}

int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    cout << "Sum: " << sumNumbers(root) << "\n";
    return 0;
}
