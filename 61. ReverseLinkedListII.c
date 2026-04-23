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

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    struct ListNode dummy = {0, head};
    struct ListNode *prev = &dummy;
    for (int i = 1; i < left; ++i) prev = prev->next;
    struct ListNode *curr = prev->next;
    for (int i = 0; i < right - left; ++i) {
        struct ListNode *move = curr->next;
        curr->next = move->next;
        move->next = prev->next;
        prev->next = move;
    }
    return dummy.next;
}

int main(void) {
    struct ListNode *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    for (struct ListNode *p = reverseBetween(head, 2, 4); p; p = p->next) printf("%d ", p->val);
    puts("");
    return 0;
}
