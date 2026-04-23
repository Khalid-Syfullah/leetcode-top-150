#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(3);

    vector<int> r1 = solution.rightSideView(root1);
    cout << "[";
    for (size_t i = 0; i < r1.size(); i++) { if (i) cout << ", "; cout << r1[i]; }
    cout << "]\n";

    vector<int> r2 = solution.rightSideView(root2);
    cout << "[";
    for (size_t i = 0; i < r2.size(); i++) { if (i) cout << ", "; cout << r2[i]; }
    cout << "]\n";

    vector<int> r3 = solution.rightSideView(nullptr);
    cout << "[";
    for (size_t i = 0; i < r3.size(); i++) { if (i) cout << ", "; cout << r3[i]; }
    cout << "]\n";
    return 0;
}
