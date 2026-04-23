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

ListNode* partition(ListNode* head, int x) {
    ListNode lessDummy, greaterDummy;
    ListNode* lessTail = &lessDummy;
    ListNode* greaterTail = &greaterDummy;
    ListNode* curr = head;
    while (curr != nullptr) {
        if (curr->val < x) {
            lessTail->next = curr;
            lessTail = lessTail->next;
        } else {
            greaterTail->next = curr;
            greaterTail = greaterTail->next;
        }
        curr = curr->next;
    }
    greaterTail->next = nullptr;
    lessTail->next = greaterDummy.next;
    return lessDummy.next;
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
    ListNode* a = build({1,4,3,2,5,2});
    print(partition(a, 3));

    ListNode* b = build({2,1});
    print(partition(b, 2));
    return 0;
}
