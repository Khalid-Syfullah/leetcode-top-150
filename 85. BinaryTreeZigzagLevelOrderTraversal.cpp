#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int levelSize = q.size();
            deque<int> level;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (leftToRight) {
                    level.push_back(node->val);
                } else {
                    level.push_front(node->val);
                }
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            result.push_back(vector<int>(level.begin(), level.end()));
            leftToRight = !leftToRight;
        }
        return result;
    }
};

void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        if (i) cout << ", ";
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            if (j) cout << ", ";
            cout << result[i][j];
        }
        cout << "]";
    }
    cout << "]\n";
}

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    printResult(solution.zigzagLevelOrder(root));
    printResult(solution.zigzagLevelOrder(nullptr));
    return 0;
}
