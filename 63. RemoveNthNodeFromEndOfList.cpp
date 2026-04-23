#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;
    while (fast != nullptr) { fast = fast->next; slow = slow->next; }
    slow->next = slow->next->next;
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
    ListNode* a = build({1,2,3,4,5});
    print(removeNthFromEnd(a, 2));

    ListNode* b = build({1});
    print(removeNthFromEnd(b, 1));

    ListNode* c = build({1,2});
    print(removeNthFromEnd(c, 1));
    return 0;
}
