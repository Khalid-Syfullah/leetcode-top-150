#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int preorderIndex;
unordered_map<int, int> inorderPos;

TreeNode* build(vector<int>& preorder, int left, int right) {
    if (left > right) return nullptr;
    int rootVal = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootVal);
    int mid = inorderPos[rootVal];
    root->left = build(preorder, left, mid - 1);
    root->right = build(preorder, mid + 1, right);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    preorderIndex = 0;
    inorderPos.clear();
    for (int i = 0; i < (int)inorder.size(); i++) inorderPos[inorder[i]] = i;
    return build(preorder, 0, (int)inorder.size() - 1);
}

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPreorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    printPreorder(root);
    cout << "\n";
    printInorder(root);
    cout << "\n";
    return 0;
}
