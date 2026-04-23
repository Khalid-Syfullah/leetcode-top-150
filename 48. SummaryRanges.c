#include <stdio.h>

void summaryRanges(int *nums, int n) {
    for (int i = 0; i < n; ) {
        int start = nums[i], end = start;
        while (i + 1 < n && nums[i + 1] == nums[i] + 1) end = nums[++i];
        if (start == end) printf("%d\n", start);
        else printf("%d->%d\n", start, end);
        ++i;
    }
}

int main(void) {
    int nums[] = {0, 1, 2, 4, 5, 7};
    summaryRanges(nums, 6);
    return 0;
}
