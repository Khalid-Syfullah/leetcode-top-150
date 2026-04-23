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

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (root == nullptr) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        double sum = 0;
        for (int i = 0; i < size; i++) {
            TreeNode* n = q.front();
            q.pop();
            sum += n->val;
            if (n->left != nullptr) q.push(n->left);
            if (n->right != nullptr) q.push(n->right);
        }
        res.push_back(sum / size);
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<double> res = averageOfLevels(root);
    cout << "[";
    for (size_t i = 0; i < res.size(); i++) { if (i) cout << ", "; cout << res[i]; }
    cout << "]\n";
    return 0;
}
