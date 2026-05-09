#include <stdbool.h>
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

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main(void) {
    /* Cycle: 3 -> 2 -> 0 -> -4 -> (back to 2) */
    struct ListNode *a = newNode(3);
    struct ListNode *b = newNode(2);
    struct ListNode *c = newNode(0);
    struct ListNode *d = newNode(-4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;
    printf("%s\n", hasCycle(a) ? "true" : "false");

    /* No cycle: 1 -> 2 */
    struct ListNode *x = newNode(1);
    struct ListNode *y = newNode(2);
    x->next = y;
    printf("%s\n", hasCycle(x) ? "true" : "false");

    return 0;
}
