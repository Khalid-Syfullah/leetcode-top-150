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

static struct ListNode *getKth(struct ListNode *start, int k) {
    while (start != NULL && k > 0) {
        start = start->next;
        k--;
    }
    return start;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    if (head == NULL || k <= 1) return head;

    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode *groupPrev = &dummy;

    while (1) {
        struct ListNode *kth = getKth(groupPrev, k);
        if (kth == NULL) break;

        struct ListNode *groupNext = kth->next;
        struct ListNode *prev = groupNext;
        struct ListNode *curr = groupPrev->next;

        while (curr != groupNext) {
            struct ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        struct ListNode *oldGroupHead = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = oldGroupHead;
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
    int v1[] = {1, 2, 3, 4, 5};
    struct ListNode *a = build(v1, 5);
    printList(reverseKGroup(a, 2));

    int v2[] = {1, 2, 3, 4, 5};
    struct ListNode *b = build(v2, 5);
    printList(reverseKGroup(b, 3));

    return 0;
}
