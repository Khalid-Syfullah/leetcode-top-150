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
    struct ListNode lessDummy, greaterDummy;
    lessDummy.next = NULL;
    greaterDummy.next = NULL;
    struct ListNode *lessTail = &lessDummy;
    struct ListNode *greaterTail = &greaterDummy;

    struct ListNode *curr = head;
    while (curr != NULL) {
        if (curr->val < x) {
            lessTail->next = curr;
            lessTail = lessTail->next;
        } else {
            greaterTail->next = curr;
            greaterTail = greaterTail->next;
        }
        curr = curr->next;
    }

    greaterTail->next = NULL;
    lessTail->next = greaterDummy.next;

    return lessDummy.next;
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
    int v1[] = {1, 4, 3, 2, 5, 2};
    struct ListNode *a = build(v1, 6);
    printList(partition(a, 3));

    int v2[] = {2, 1};
    struct ListNode *b = build(v2, 2);
    printList(partition(b, 2));

    return 0;
}
