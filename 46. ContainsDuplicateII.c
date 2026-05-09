#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HT_SIZE 2048

typedef struct Node {
    int key;
    int idx;
    struct Node *next;
} Node;

static Node *ht[HT_SIZE];
static Node pool[10000];
static int poolIdx;

static void ht_clear(void) {
    memset(ht, 0, sizeof(ht));
    poolIdx = 0;
}

static unsigned int ht_hash(int key) {
    return (unsigned int)(key < 0 ? (-key) ^ 0xFFFF : key) % HT_SIZE;
}

/* Returns previous index stored for key, or -1 if not found.
   Then updates the stored index to newIdx. */
static int ht_getset(int key, int newIdx) {
    unsigned int h = ht_hash(key);
    for (Node *n = ht[h]; n; n = n->next) {
        if (n->key == key) {
            int old = n->idx;
            n->idx = newIdx;
            return old;
        }
    }
    Node *n = &pool[poolIdx++];
    n->key = key; n->idx = newIdx;
    n->next = ht[h]; ht[h] = n;
    return -1;
}

bool containsNearbyDuplicate(int *nums, int n, int k) {
    ht_clear();
    for (int i = 0; i < n; i++) {
        int j = ht_getset(nums[i], i);
        if (j >= 0 && i - j <= k) return true;
    }
    return false;
}

int main(void) {
    int a[] = {1, 2, 3, 1};
    puts(containsNearbyDuplicate(a, 4, 3) ? "true" : "false"); // true

    int b[] = {1, 0, 1, 1};
    puts(containsNearbyDuplicate(b, 4, 1) ? "true" : "false"); // true

    int c[] = {1, 2, 3, 1, 2, 3};
    puts(containsNearbyDuplicate(c, 6, 2) ? "true" : "false"); // false

    return 0;
}
