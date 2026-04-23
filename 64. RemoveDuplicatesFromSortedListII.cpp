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

ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    while (head != nullptr) {
        if (head->next != nullptr && head->val == head->next->val) {
            int duplicateVal = head->val;
            while (head != nullptr && head->val == duplicateVal) head = head->next;
            prev->next = head;
        } else {
            prev = prev->next;
            head = head->next;
        }
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
    ListNode* a = build({1,2,3,3,4,4,5});
    ListNode* b = build({1,1,1,2,3});
    ListNode* c = build({1,1});
    print(deleteDuplicates(a));
    print(deleteDuplicates(b));
    print(deleteDuplicates(c));
    return 0;
}
