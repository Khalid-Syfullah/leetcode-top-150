#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy.next;
}

ListNode* build(vector<int> values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : values) { tail->next = new ListNode(v); tail = tail->next; }
    return dummy.next;
}

void print(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    ListNode* l1 = build({2,4,3});
    ListNode* l2 = build({5,6,4});
    print(addTwoNumbers(l1, l2));

    ListNode* l3 = build({9,9,9,9,9,9,9});
    ListNode* l4 = build({9,9,9,9});
    print(addTwoNumbers(l3, l4));
    return 0;
}
