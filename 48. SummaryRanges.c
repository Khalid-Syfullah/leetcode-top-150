#include <stdio.h>

void summaryRanges(int *nums, int n) {
    int i = 0;
    printf("[");
    int first = 1;
    while (i < n) {
        int start = nums[i];
        while (i + 1 < n && nums[i + 1] == nums[i] + 1) i++;
        if (!first) printf(", ");
        first = 0;
        if (start == nums[i]) printf("%d", start);
        else printf("%d->%d", start, nums[i]);
        i++;
    }
    printf("]\n");
}

int main(void) {
    int a[] = {0, 1, 2, 4, 5, 7};
    summaryRanges(a, 6);    // [0->2, 4->5, 7]

    int b[] = {0, 2, 3, 4, 6, 8, 9};
    summaryRanges(b, 7);    // [0, 2->4, 6, 8->9]

    summaryRanges(NULL, 0); // []

    return 0;
}
