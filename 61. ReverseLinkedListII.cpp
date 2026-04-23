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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr || left == right) return head;
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    for (int i = 1; i < left; i++) prev = prev->next;
    ListNode* curr = prev->next;
    for (int i = 0; i < right - left; i++) {
        ListNode* move = curr->next;
        curr->next = move->next;
        move->next = prev->next;
        prev->next = move;
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
    print(reverseBetween(a, 2, 4));

    ListNode* b = build({5});
    print(reverseBetween(b, 1, 1));
    return 0;
}
