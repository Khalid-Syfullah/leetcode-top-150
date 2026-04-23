#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
    int prev;
    int minDiff;

    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        if (prev != -1) {
            minDiff = min(minDiff, node->val - prev);
        }
        prev = node->val;
        inorder(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        prev = -1;
        minDiff = INT_MAX;
        inorder(root);
        return minDiff;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(2);

    cout << solution.getMinimumDifference(root1) << "\n";
    cout << solution.getMinimumDifference(root2) << "\n";
    return 0;
}
