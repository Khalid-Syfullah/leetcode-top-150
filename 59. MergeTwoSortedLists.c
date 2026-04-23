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

struct ListNode *mergeTwoLists(struct ListNode *a, struct ListNode *b) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

int main(void) {
    struct ListNode *a = newNode(1);
    a->next = newNode(2);
    a->next->next = newNode(4);
    struct ListNode *b = newNode(1);
    b->next = newNode(3);
    b->next->next = newNode(4);
    for (struct ListNode *p = mergeTwoLists(a, b); p; p = p->next) printf("%d ", p->val);
    puts("");
    return 0;
}
