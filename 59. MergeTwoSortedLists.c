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

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = (list1 != NULL) ? list1 : list2;
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
    int v1[] = {1, 2, 4};
    int v2[] = {1, 3, 4};
    struct ListNode *l1 = build(v1, 3);
    struct ListNode *l2 = build(v2, 3);
    printList(mergeTwoLists(l1, l2));

    struct ListNode *l3 = build(NULL, 0);
    struct ListNode *l4 = build(NULL, 0);
    printList(mergeTwoLists(l3, l4));

    return 0;
}
