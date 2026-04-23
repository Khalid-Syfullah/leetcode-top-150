#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxSum;

    Solution() : maxSum(INT_MIN) {}

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);
        maxSum = max(maxSum, node->val + left + right);
        return node->val + max(left, right);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(-10);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    cout << "Test 1: " << Solution().maxPathSum(root1) << "\n";

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    cout << "Test 2: " << Solution().maxPathSum(root2) << "\n";

    TreeNode* root3 = new TreeNode(-3);
    cout << "Test 3: " << Solution().maxPathSum(root3) << "\n";
    return 0;
}
