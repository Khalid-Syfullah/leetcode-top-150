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

/* Min-heap of ListNode pointers */
static struct ListNode **heap;
static int heapSize;

static void heapSwap(int i, int j) {
    struct ListNode *tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

static void heapPush(struct ListNode *node) {
    heap[heapSize++] = node;
    int i = heapSize - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent]->val > heap[i]->val) {
            heapSwap(parent, i);
            i = parent;
        } else break;
    }
}

static struct ListNode *heapPop(void) {
    struct ListNode *top = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int smallest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < heapSize && heap[left]->val < heap[smallest]->val) smallest = left;
        if (right < heapSize && heap[right]->val < heap[smallest]->val) smallest = right;
        if (smallest == i) break;
        heapSwap(i, smallest);
        i = smallest;
    }
    return top;
}

static struct ListNode *mergeKLists(struct ListNode **lists, int k) {
    heap = malloc(k * sizeof(struct ListNode *));
    heapSize = 0;
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL) heapPush(lists[i]);
    }
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    while (heapSize > 0) {
        struct ListNode *node = heapPop();
        tail->next = node;
        tail = tail->next;
        if (node->next != NULL) heapPush(node->next);
    }
    free(heap);
    return dummy.next;
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
    int v1[] = {1, 4, 5};
    int v2[] = {1, 3, 4};
    int v3[] = {2, 6};
    struct ListNode *lists[3];
    lists[0] = build(v1, 3);
    lists[1] = build(v2, 3);
    lists[2] = build(v3, 2);
    struct ListNode *merged = mergeKLists(lists, 3);
    printList(merged);
    return 0;
}
