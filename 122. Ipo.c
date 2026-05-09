#include <stdio.h>
#include <stdlib.h>

/* Project: [capital, profit] */
typedef struct {
    int capital;
    int profit;
} Project;

static int cmpProject(const void *a, const void *b) {
    return ((Project *)a)->capital - ((Project *)b)->capital;
}

/* Max-heap for profits */
static int *maxHeap;
static int maxHeapSize;

static void maxHeapSwap(int i, int j) {
    int tmp = maxHeap[i]; maxHeap[i] = maxHeap[j]; maxHeap[j] = tmp;
}

static void maxHeapPush(int val) {
    maxHeap[maxHeapSize++] = val;
    int i = maxHeapSize - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (maxHeap[parent] < maxHeap[i]) {
            maxHeapSwap(parent, i);
            i = parent;
        } else break;
    }
}

static int maxHeapPop(void) {
    int top = maxHeap[0];
    maxHeap[0] = maxHeap[--maxHeapSize];
    int i = 0;
    while (1) {
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < maxHeapSize && maxHeap[left] > maxHeap[largest]) largest = left;
        if (right < maxHeapSize && maxHeap[right] > maxHeap[largest]) largest = right;
        if (largest == i) break;
        maxHeapSwap(i, largest);
        i = largest;
    }
    return top;
}

static int findMaximizedCapital(int k, int w, int *profits, int *capital, int n) {
    Project *projects = malloc(n * sizeof(Project));
    for (int i = 0; i < n; i++) {
        projects[i].capital = capital[i];
        projects[i].profit = profits[i];
    }
    qsort(projects, n, sizeof(Project), cmpProject);

    maxHeap = malloc(n * sizeof(int));
    maxHeapSize = 0;
    int currentCapital = w;
    int index = 0;

    for (int i = 0; i < k; i++) {
        while (index < n && projects[index].capital <= currentCapital) {
            maxHeapPush(projects[index].profit);
            index++;
        }
        if (maxHeapSize == 0) break;
        currentCapital += maxHeapPop();
    }

    free(projects);
    free(maxHeap);
    return currentCapital;
}

int main(void) {
    int profits1[] = {1, 2, 3};
    int capital1[] = {0, 1, 1};
    printf("%d\n", findMaximizedCapital(2, 0, profits1, capital1, 3));  /* 4 */

    int profits2[] = {1, 2, 3};
    int capital2[] = {0, 1, 2};
    printf("%d\n", findMaximizedCapital(3, 0, profits2, capital2, 3));  /* 6 */
    return 0;
}
