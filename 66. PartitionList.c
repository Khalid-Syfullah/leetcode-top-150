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

struct ListNode *partition(struct ListNode *head, int x) {
    struct ListNode lessDummy = {0, NULL}, geDummy = {0, NULL};
    struct ListNode *less = &lessDummy, *ge = &geDummy;
    while (head) {
        if (head->val < x) {
            less->next = head;
            less = less->next;
        } else {
            ge->next = head;
            ge = ge->next;
        }
        head = head->next;
    }
    ge->next = NULL;
    less->next = geDummy.next;
    return lessDummy.next;
}

int main(void) {
    struct ListNode *head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(2);
    for (struct ListNode *p = partition(head, 3); p; p = p->next) printf("%d ", p->val);
    puts("");
    return 0;
}
