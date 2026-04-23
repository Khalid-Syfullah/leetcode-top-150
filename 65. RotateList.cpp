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

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) return head;
    int length = 1;
    ListNode* tail = head;
    while (tail->next != nullptr) { tail = tail->next; length++; }
    k %= length;
    if (k == 0) return head;
    tail->next = head;
    int stepsToNewTail = length - k - 1;
    ListNode* newTail = head;
    for (int i = 0; i < stepsToNewTail; i++) newTail = newTail->next;
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

ListNode* build(vector<int> values) {
    ListNode dummy;
    ListNode* cur = &dummy;
    for (int v : values) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy.next;
}

void print(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val;
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << "\n";
}

int main() {
    ListNode* a = build({1,2,3,4,5});
    print(rotateRight(a, 2));

    ListNode* b = build({0,1,2});
    print(rotateRight(b, 4));
    return 0;
}
