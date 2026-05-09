#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 2048

typedef struct Node {
    int key;
    int idx;
    struct Node *next;
} Node;

static Node *ht[HT_SIZE];
static Node pool[HT_SIZE];
static int poolIdx;

static void ht_clear(void) {
    memset(ht, 0, sizeof(ht));
    poolIdx = 0;
}

static unsigned int ht_hash(int key) {
    return (unsigned int)(key < 0 ? -key : key) % HT_SIZE;
}

static int ht_get(int key) {
    unsigned int h = ht_hash(key);
    for (Node *n = ht[h]; n; n = n->next)
        if (n->key == key) return n->idx;
    return -1;
}

static void ht_put(int key, int idx) {
    unsigned int h = ht_hash(key);
    Node *n = &pool[poolIdx++];
    n->key = key; n->idx = idx;
    n->next = ht[h]; ht[h] = n;
}

void twoSum(int *nums, int n, int target, int *a, int *b) {
    ht_clear();
    for (int i = 0; i < n; i++) {
        int j = ht_get(target - nums[i]);
        if (j >= 0) { *a = j; *b = i; return; }
        ht_put(nums[i], i);
    }
    *a = *b = -1;
}

int main(void) {
    int a, b;

    int nums1[] = {2, 7, 11, 15};
    twoSum(nums1, 4, 9, &a, &b);
    printf("[%d, %d]\n", a, b); // [0, 1]

    int nums2[] = {3, 2, 4};
    twoSum(nums2, 3, 6, &a, &b);
    printf("[%d, %d]\n", a, b); // [1, 2]

    int nums3[] = {3, 3};
    twoSum(nums3, 2, 6, &a, &b);
    printf("[%d, %d]\n", a, b); // [0, 1]

    return 0;
}
