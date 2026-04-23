#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int val) : val(val), left(nullptr), right(nullptr), next(nullptr) {}
};

Node* connect(Node* root) {
    Node* currentLevel = root;
    while (currentLevel != nullptr) {
        Node dummy(0);
        Node* tail = &dummy;
        while (currentLevel != nullptr) {
            if (currentLevel->left != nullptr) {
                tail->next = currentLevel->left;
                tail = tail->next;
            }
            if (currentLevel->right != nullptr) {
                tail->next = currentLevel->right;
                tail = tail->next;
            }
            currentLevel = currentLevel->next;
        }
        currentLevel = dummy.next;
    }
    return root;
}

void printByNext(Node* root) {
    Node* levelStart = root;
    while (levelStart != nullptr) {
        Node* curr = levelStart;
        levelStart = nullptr;
        while (curr != nullptr) {
            cout << curr->val << " ";
            if (levelStart == nullptr) {
                if (curr->left != nullptr) levelStart = curr->left;
                else if (curr->right != nullptr) levelStart = curr->right;
            }
            curr = curr->next;
        }
        cout << "#\n";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    connect(root);
    printByNext(root);
    return 0;
}
