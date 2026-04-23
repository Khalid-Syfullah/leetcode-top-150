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

int postIndex;
unordered_map<int, int> inorderPos;

TreeNode* build(vector<int>& postorder, int left, int right) {
    if (left > right) return nullptr;
    int rootVal = postorder[postIndex--];
    TreeNode* root = new TreeNode(rootVal);
    int mid = inorderPos[rootVal];
    root->right = build(postorder, mid + 1, right);
    root->left = build(postorder, left, mid - 1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    inorderPos.clear();
    for (int i = 0; i < (int)inorder.size(); i++) inorderPos[inorder[i]] = i;
    postIndex = (int)postorder.size() - 1;
    return build(postorder, 0, (int)inorder.size() - 1);
}

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPostorder(TreeNode* root) {
    if (root == nullptr) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = buildTree(inorder, postorder);
    printInorder(root);
    cout << "\n";
    printPostorder(root);
    cout << "\n";
    return 0;
}
