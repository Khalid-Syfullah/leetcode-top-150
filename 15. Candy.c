#include <stdio.h>

int candy(int *ratings, int ratingsSize) {
    int left[20000];
    for (int i = 0; i < ratingsSize; ++i) left[i] = 1;
    for (int i = 1; i < ratingsSize; ++i) {
        if (ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
    }
    int right = 1, total = left[ratingsSize - 1];
    for (int i = ratingsSize - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) ++right;
        else right = 1;
        total += left[i] > right ? left[i] : right;
    }
    return total;
}

int main(void) {
    int ratings[] = {1, 0, 2};
    printf("%d\n", candy(ratings, 3));
    return 0;
}
