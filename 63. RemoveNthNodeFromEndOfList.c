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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode dummy = {0, head};
    struct ListNode *fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; ++i) fast = fast->next;
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode *del = slow->next;
    slow->next = del->next;
    free(del);
    return dummy.next;
}

int main(void) {
    struct ListNode *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    for (struct ListNode *p = removeNthFromEnd(head, 2); p; p = p->next) printf("%d ", p->val);
    puts("");
    return 0;
}
