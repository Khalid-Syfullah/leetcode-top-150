#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    cout << boolalpha;
    TreeNode* a = new TreeNode(1); a->left = new TreeNode(2); a->right = new TreeNode(3);
    TreeNode* b = new TreeNode(1); b->left = new TreeNode(2); b->right = new TreeNode(3);
    cout << isSameTree(a, b) << "\n";

    TreeNode* c = new TreeNode(1); c->left = new TreeNode(2);
    TreeNode* d = new TreeNode(1); d->right = new TreeNode(2);
    cout << isSameTree(c, d) << "\n";
    return 0;
}
