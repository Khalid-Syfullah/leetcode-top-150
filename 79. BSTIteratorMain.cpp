#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BSTIterator {
    stack<TreeNode*> stk;

    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        pushLeft(node->right);
        return node->val;
    }

    bool hasNext() {
        return !stk.empty();
    }
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);

    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << "\n";
    cout << boolalpha << iterator.hasNext() << "\n";
    return 0;
}
