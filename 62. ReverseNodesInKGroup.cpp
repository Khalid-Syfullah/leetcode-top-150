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

ListNode* getKth(ListNode* start, int k) {
    while (start != nullptr && k > 0) { start = start->next; k--; }
    return start;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k <= 1) return head;
    ListNode dummy(0, head);
    ListNode* groupPrev = &dummy;
    while (true) {
        ListNode* kth = getKth(groupPrev, k);
        if (kth == nullptr) break;
        ListNode* groupNext = kth->next;
        ListNode* prev = groupNext;
        ListNode* curr = groupPrev->next;
        while (curr != groupNext) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* oldGroupHead = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = oldGroupHead;
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
    ListNode* a = build({1,2,3,4,5});
    print(reverseKGroup(a, 2));

    ListNode* b = build({1,2,3,4,5});
    print(reverseKGroup(b, 3));
    return 0;
}
