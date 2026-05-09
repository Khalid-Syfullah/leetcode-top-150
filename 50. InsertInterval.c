#include <stdio.h>

/* intervals: n x 2 array; newInterval: length-2 array */
void insert(int (*intervals)[2], int n, int *newInterval) {
    int i = 0;

    /* Add all intervals that end before newInterval starts */
    while (i < n && intervals[i][1] < newInterval[0]) {
        printf("[%d, %d]\n", intervals[i][0], intervals[i][1]);
        i++;
    }

    /* Merge overlapping intervals into newInterval */
    while (i < n && intervals[i][0] <= newInterval[1]) {
        if (intervals[i][0] < newInterval[0]) newInterval[0] = intervals[i][0];
        if (intervals[i][1] > newInterval[1]) newInterval[1] = intervals[i][1];
        i++;
    }
    printf("[%d, %d]\n", newInterval[0], newInterval[1]);

    /* Add remaining intervals */
    while (i < n) {
        printf("[%d, %d]\n", intervals[i][0], intervals[i][1]);
        i++;
    }
}

int main(void) {
    int iv1[][2] = {{1,3},{6,9}};
    int ni1[] = {2, 5};
    insert(iv1, 2, ni1);
    printf("\n");

    int iv2[][2] = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    int ni2[] = {4, 8};
    insert(iv2, 5, ni2);

    return 0;
}
