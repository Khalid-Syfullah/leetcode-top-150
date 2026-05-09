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

struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    int length = 1;
    struct ListNode *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    k %= length;
    if (k == 0) return head;

    tail->next = head;

    int stepsToNewTail = length - k - 1;
    struct ListNode *newTail = head;
    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    struct ListNode *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

static struct ListNode *build(int *values, int n) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *cur = &dummy;
    for (int i = 0; i < n; i++) {
        cur->next = newNode(values[i]);
        cur = cur->next;
    }
    return dummy.next;
}

static void printList(struct ListNode *head) {
    struct ListNode *cur = head;
    while (cur != NULL) {
        printf("%d", cur->val);
        if (cur->next != NULL) printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}

int main(void) {
    int v1[] = {1, 2, 3, 4, 5};
    struct ListNode *a = build(v1, 5);
    printList(rotateRight(a, 2));

    int v2[] = {0, 1, 2};
    struct ListNode *b = build(v2, 3);
    printList(rotateRight(b, 4));

    return 0;
}
