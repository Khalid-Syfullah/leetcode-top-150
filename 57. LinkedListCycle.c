#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main(void) {
    struct ListNode *a = malloc(sizeof(*a));
    struct ListNode *b = malloc(sizeof(*b));
    struct ListNode *c = malloc(sizeof(*c));
    a->val = 3; b->val = 2; c->val = 0;
    a->next = b; b->next = c; c->next = b;
    puts(hasCycle(a) ? "true" : "false");
    c->next = NULL;
    free(c); free(b); free(a);
    return 0;
}
