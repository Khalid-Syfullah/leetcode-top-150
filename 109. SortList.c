#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode *newNode(int val) {
    struct ListNode *node = malloc(sizeof(*node));
    node->val = val;
    node->next = NULL;
    return node;
}

static struct ListNode *getMid(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

static struct ListNode *merge(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}

static struct ListNode *sortList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *mid = getMid(head);
    struct ListNode *rightHead = mid->next;
    mid->next = NULL;
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(rightHead);
    return merge(left, right);
}

static struct ListNode *build(int *vals, int n) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    for (int i = 0; i < n; i++) {
        tail->next = newNode(vals[i]);
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
    int v1[] = {4, 2, 1, 3};
    struct ListNode *head1 = build(v1, 4);
    printList(sortList(head1));

    int v2[] = {-1, 5, 3, 4, 0};
    struct ListNode *head2 = build(v2, 5);
    printList(sortList(head2));
    return 0;
}
