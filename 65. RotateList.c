#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *newNode(int val) {
    struct ListNode *node = malloc(sizeof(*node));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (!head || !head->next || k == 0) return head;
    int len = 1;
    struct ListNode *tail = head;
    while (tail->next) {
        tail = tail->next;
        ++len;
    }
    k %= len;
    if (k == 0) return head;
    tail->next = head;
    for (int i = 0; i < len - k; ++i) tail = tail->next;
    struct ListNode *newHead = tail->next;
    tail->next = NULL;
    return newHead;
}

int main(void) {
    struct ListNode *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    for (struct ListNode *p = rotateRight(head, 2); p; p = p->next) printf("%d ", p->val);
    puts("");
    return 0;
}
