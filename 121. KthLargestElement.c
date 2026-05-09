#include <stdio.h>
#include <stdlib.h>

/* Min-heap of size k to find kth largest */
static int *heap;
static int heapSize;

static void heapSwap(int i, int j) {
    int tmp = heap[i]; heap[i] = heap[j]; heap[j] = tmp;
}

static void heapPush(int val) {
    heap[heapSize++] = val;
    int i = heapSize - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            heapSwap(parent, i);
            i = parent;
        } else break;
    }
}

static void heapPop(void) {
    heap[0] = heap[--heapSize];
    int i = 0;
    while (1) {
        int smallest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < heapSize && heap[left] < heap[smallest]) smallest = left;
        if (right < heapSize && heap[right] < heap[smallest]) smallest = right;
        if (smallest == i) break;
        heapSwap(i, smallest);
        i = smallest;
    }
}

static int findKthLargest(int *nums, int n, int k) {
    heap = malloc(k * sizeof(int));
    heapSize = 0;
    for (int i = 0; i < n; i++) {
        heapPush(nums[i]);
        if (heapSize > k) heapPop();
    }
    int result = heap[0];
    free(heap);
    return result;
}

int main(void) {
    int nums1[] = {3, 2, 1, 5, 6, 4};
    printf("%d\n", findKthLargest(nums1, 6, 2));  /* 5 */
    int nums2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    printf("%d\n", findKthLargest(nums2, 9, 4));  /* 4 */
    return 0;
}
