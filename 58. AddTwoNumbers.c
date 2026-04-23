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

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *tail = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        tail->next = newNode(sum % 10);
        tail = tail->next;
    }
    return dummy.next;
}

static void printList(struct ListNode *head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    puts("");
}

int main(void) {
    struct ListNode *a = newNode(2);
    a->next = newNode(4);
    a->next->next = newNode(3);
    struct ListNode *b = newNode(5);
    b->next = newNode(6);
    b->next->next = newNode(4);
    printList(addTwoNumbers(a, b));
    return 0;
}
