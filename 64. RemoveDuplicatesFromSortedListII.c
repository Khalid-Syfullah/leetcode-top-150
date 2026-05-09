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

struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode *prev = &dummy;

    while (head != NULL) {
        if (head->next != NULL && head->val == head->next->val) {
            int dupVal = head->val;
            while (head != NULL && head->val == dupVal) {
                head = head->next;
            }
            prev->next = head;
        } else {
            prev = prev->next;
            head = head->next;
        }
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
    int v1[] = {1, 2, 3, 3, 4, 4, 5};
    struct ListNode *a = build(v1, 7);
    printList(deleteDuplicates(a));

    int v2[] = {1, 1, 1, 2, 3};
    struct ListNode *b = build(v2, 5);
    printList(deleteDuplicates(b));

    int v3[] = {1, 1};
    struct ListNode *c = build(v3, 2);
    printList(deleteDuplicates(c));

    return 0;
}
