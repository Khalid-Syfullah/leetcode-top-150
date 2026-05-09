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
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    for (int i = 0; i <= n; i++) fast = fast->next;

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode *del = slow->next;
    slow->next = del->next;
    free(del);
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
    printList(removeNthFromEnd(a, 2));

    int v2[] = {1};
    struct ListNode *b = build(v2, 1);
    printList(removeNthFromEnd(b, 1));

    int v3[] = {1, 2};
    struct ListNode *c = build(v3, 2);
    printList(removeNthFromEnd(c, 1));

    return 0;
}
