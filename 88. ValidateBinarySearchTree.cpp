#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
    bool validate(TreeNode* node, long long* low, long long* high) {
        if (node == nullptr) return true;
        if ((low != nullptr && node->val <= *low) || (high != nullptr && node->val >= *high)) {
            return false;
        }
        long long nodeVal = node->val;
        return validate(node->left, low, &nodeVal) && validate(node->right, &nodeVal, high);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};

int main() {
    Solution solution;

    TreeNode* validRoot = new TreeNode(2);
    validRoot->left = new TreeNode(1);
    validRoot->right = new TreeNode(3);

    TreeNode* invalidRoot = new TreeNode(5);
    invalidRoot->left = new TreeNode(1);
    invalidRoot->right = new TreeNode(4);
    invalidRoot->right->left = new TreeNode(3);
    invalidRoot->right->right = new TreeNode(6);

    cout << boolalpha;
    cout << solution.isValidBST(validRoot) << "\n";
    cout << solution.isValidBST(invalidRoot) << "\n";
    return 0;
}
