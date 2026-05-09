#include <stdio.h>
#include <stdlib.h>

/* Max-heap for the lower half (small) */
static int *small;
static int smallSize;
static int smallCap;

/* Min-heap for the upper half (large) */
static int *large;
static int largeSize;
static int largeCap;

static void smallSwap(int i, int j) {
    int tmp = small[i]; small[i] = small[j]; small[j] = tmp;
}

static void largeSwap(int i, int j) {
    int tmp = large[i]; large[i] = large[j]; large[j] = tmp;
}

static void smallPush(int val) {
    if (smallSize == smallCap) {
        smallCap *= 2;
        small = realloc(small, smallCap * sizeof(int));
    }
    small[smallSize++] = val;
    int i = smallSize - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (small[parent] < small[i]) { smallSwap(parent, i); i = parent; }
        else break;
    }
}

static int smallPop(void) {
    int top = small[0];
    small[0] = small[--smallSize];
    int i = 0;
    while (1) {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < smallSize && small[l] > small[largest]) largest = l;
        if (r < smallSize && small[r] > small[largest]) largest = r;
        if (largest == i) break;
        smallSwap(i, largest); i = largest;
    }
    return top;
}

static void largePush(int val) {
    if (largeSize == largeCap) {
        largeCap *= 2;
        large = realloc(large, largeCap * sizeof(int));
    }
    large[largeSize++] = val;
    int i = largeSize - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (large[parent] > large[i]) { largeSwap(parent, i); i = parent; }
        else break;
    }
}

static int largePop(void) {
    int top = large[0];
    large[0] = large[--largeSize];
    int i = 0;
    while (1) {
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < largeSize && large[l] < large[smallest]) smallest = l;
        if (r < largeSize && large[r] < large[smallest]) smallest = r;
        if (smallest == i) break;
        largeSwap(i, smallest); i = smallest;
    }
    return top;
}

static void initMedianFinder(void) {
    smallCap = 16; smallSize = 0;
    small = malloc(smallCap * sizeof(int));
    largeCap = 16; largeSize = 0;
    large = malloc(largeCap * sizeof(int));
}

static void addNum(int num) {
    smallPush(num);
    largePush(smallPop());
    if (largeSize > smallSize) {
        smallPush(largePop());
    }
}

static double findMedian(void) {
    if (smallSize > largeSize) return small[0];
    return (small[0] + large[0]) / 2.0;
}

int main(void) {
    initMedianFinder();
    addNum(1);
    addNum(2);
    printf("%.1f\n", findMedian());  /* 1.5 */
    addNum(3);
    printf("%.1f\n", findMedian());  /* 2.0 */
    free(small);
    free(large);
    return 0;
}
