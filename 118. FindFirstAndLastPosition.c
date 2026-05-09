#include <stdio.h>

static int findBound(int *nums, int n, int target, int isFirst) {
    int left = 0;
    int right = n - 1;
    int answer = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            answer = mid;
            if (isFirst) right = mid - 1;
            else left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

static void searchRange(int *nums, int n, int target) {
    if (n == 0) {
        printf("[-1, -1]\n");
        return;
    }
    int first = findBound(nums, n, target, 1);
    if (first == -1) {
        printf("[-1, -1]\n");
        return;
    }
    int last = findBound(nums, n, target, 0);
    printf("[%d, %d]\n", first, last);
}

int main(void) {
    int nums1[] = {5, 7, 7, 8, 8, 10};
    searchRange(nums1, 6, 8);
    searchRange(nums1, 6, 6);
    searchRange(NULL, 0, 0);
    return 0;
}
