#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node *newNode(int val) {
    struct Node *node = malloc(sizeof(*node));
    node->val = val;
    node->next = NULL;
    node->random = NULL;
    return node;
}

/*
 * Copy list with random pointer using the interleaving approach:
 * 1. Insert clones next to each original node.
 * 2. Set random pointers for clones.
 * 3. Separate the two lists.
 */
struct Node *copyRandomList(struct Node *head) {
    if (head == NULL) return NULL;

    /* Step 1: interleave clones */
    struct Node *curr = head;
    while (curr != NULL) {
        struct Node *copy = newNode(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    /* Step 2: set random pointers */
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    /* Step 3: separate lists */
    struct Node *newHead = head->next;
    curr = head;
    while (curr != NULL) {
        struct Node *copy = curr->next;
        curr->next = copy->next;
        if (copy->next != NULL) {
            copy->next = copy->next->next;
        }
        curr = curr->next;
    }

    return newHead;
}

static void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        int randomVal = (curr->random == NULL) ? -1 : curr->random->val;
        printf("val=%d, random=%d\n", curr->val, randomVal);
        curr = curr->next;
    }
}

int main(void) {
    struct Node *n1 = newNode(7);
    struct Node *n2 = newNode(13);
    struct Node *n3 = newNode(11);
    struct Node *n4 = newNode(10);
    struct Node *n5 = newNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    struct Node *copied = copyRandomList(n1);

    printf("Original:\n");
    printList(n1);
    printf("Copied:\n");
    printList(copied);

    return 0;
}
