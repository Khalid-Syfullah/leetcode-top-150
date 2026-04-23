#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    cout << boolalpha;
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(-4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;
    cout << hasCycle(a) << "\n";

    ListNode* x = new ListNode(1);
    ListNode* y = new ListNode(2);
    x->next = y;
    cout << hasCycle(x) << "\n";

    delete x; delete y;
    return 0;
}
