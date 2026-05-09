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
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        tail->next = newNode(sum % 10);
        tail = tail->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy.next;
}

static struct ListNode *build(int *values, int n) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    for (int i = 0; i < n; i++) {
        tail->next = newNode(values[i]);
        tail = tail->next;
    }
    return dummy.next;
}

static void printList(struct ListNode *head) {
    struct ListNode *curr = head;
    while (curr != NULL) {
        printf("%d", curr->val);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf("\n");
}

int main(void) {
    int v1[] = {2, 4, 3};
    int v2[] = {5, 6, 4};
    struct ListNode *l1 = build(v1, 3);
    struct ListNode *l2 = build(v2, 3);
    printList(addTwoNumbers(l1, l2));

    int v3[] = {9, 9, 9, 9, 9, 9, 9};
    int v4[] = {9, 9, 9, 9};
    struct ListNode *l3 = build(v3, 7);
    struct ListNode *l4 = build(v4, 4);
    printList(addTwoNumbers(l3, l4));

    return 0;
}
