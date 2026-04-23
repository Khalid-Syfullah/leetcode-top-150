#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    unordered_map<Node*, Node*> map;
    Node* curr = head;
    while (curr != nullptr) {
        map[curr] = new Node(curr->val);
        curr = curr->next;
    }
    curr = head;
    while (curr != nullptr) {
        Node* copy = map[curr];
        copy->next = curr->next ? map[curr->next] : nullptr;
        copy->random = curr->random ? map[curr->random] : nullptr;
        curr = curr->next;
    }
    return map[head];
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        int randomVal = curr->random ? curr->random->val : -1;
        cout << "val=" << curr->val << ", random=" << randomVal << "\n";
        curr = curr->next;
    }
}

int main() {
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;
    Node* copied = copyRandomList(n1);
    cout << "Original:\n";
    printList(n1);
    cout << "Copied:\n";
    printList(copied);
    return 0;
}
