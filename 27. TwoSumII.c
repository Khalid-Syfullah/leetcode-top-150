#include <stdio.h>

void twoSum(int *numbers, int n, int target, int *a, int *b) {
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            *a = left + 1;
            *b = right + 1;
            return;
        }
        if (sum < target) ++left;
        else --right;
    }
    *a = *b = -1;
}

int main(void) {
    int numbers[] = {2, 7, 11, 15}, a, b;
    twoSum(numbers, 4, 9, &a, &b);
    printf("[%d, %d]\n", a, b);
    return 0;
}
