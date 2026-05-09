#include <stdio.h>
#include <stdlib.h>

/* Heap entry: [nums1[i], nums2[j], j] */
typedef struct {
    int first;
    int second;
    int j;
} HeapEntry;

static HeapEntry *minHeap;
static int heapSize;

static void heapSwap(int i, int ii) {
    HeapEntry tmp = minHeap[i]; minHeap[i] = minHeap[ii]; minHeap[ii] = tmp;
}

static void heapPush(int first, int second, int j) {
    minHeap[heapSize].first = first;
    minHeap[heapSize].second = second;
    minHeap[heapSize].j = j;
    heapSize++;
    int i = heapSize - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (minHeap[parent].first + minHeap[parent].second > minHeap[i].first + minHeap[i].second) {
            heapSwap(parent, i);
            i = parent;
        } else break;
    }
}

static HeapEntry heapPop(void) {
    HeapEntry top = minHeap[0];
    minHeap[0] = minHeap[--heapSize];
    int i = 0;
    while (1) {
        int smallest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < heapSize && (minHeap[left].first + minHeap[left].second) < (minHeap[smallest].first + minHeap[smallest].second)) smallest = left;
        if (right < heapSize && (minHeap[right].first + minHeap[right].second) < (minHeap[smallest].first + minHeap[smallest].second)) smallest = right;
        if (smallest == i) break;
        heapSwap(i, smallest);
        i = smallest;
    }
    return top;
}

static void kSmallestPairs(int *nums1, int n1, int *nums2, int n2, int k) {
    if (n1 == 0 || n2 == 0 || k == 0) {
        printf("[]\n");
        return;
    }
    int initSize = k < n1 ? k : n1;
    minHeap = malloc((initSize + k) * sizeof(HeapEntry));
    heapSize = 0;
    for (int i = 0; i < initSize; i++) {
        heapPush(nums1[i], nums2[0], 0);
    }

    printf("[");
    int count = 0;
    while (k > 0 && heapSize > 0) {
        HeapEntry curr = heapPop();
        if (count > 0) printf(", ");
        printf("[%d, %d]", curr.first, curr.second);
        count++;
        if (curr.j + 1 < n2) {
            heapPush(curr.first, nums2[curr.j + 1], curr.j + 1);
        }
        k--;
    }
    printf("]\n");
    free(minHeap);
}

int main(void) {
    int nums1a[] = {1, 7, 11};
    int nums2a[] = {2, 4, 6};
    kSmallestPairs(nums1a, 3, nums2a, 3, 3);

    int nums1b[] = {1, 1, 2};
    int nums2b[] = {1, 2, 3};
    kSmallestPairs(nums1b, 3, nums2b, 3, 2);
    return 0;
}
