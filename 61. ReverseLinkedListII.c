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

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    if (head == NULL || left == right) return head;

    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode *prev = &dummy;

    for (int i = 1; i < left; i++) prev = prev->next;

    struct ListNode *curr = prev->next;
    for (int i = 0; i < right - left; i++) {
        struct ListNode *move = curr->next;
        curr->next = move->next;
        move->next = prev->next;
        prev->next = move;
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
    printList(reverseBetween(a, 2, 4));

    int v2[] = {5};
    struct ListNode *b = build(v2, 1);
    printList(reverseBetween(b, 1, 1));

    return 0;
}
