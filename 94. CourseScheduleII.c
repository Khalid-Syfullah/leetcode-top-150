#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Returns number of courses in order, 0 if cycle detected.
   order[] must have at least numCourses elements. */
int findOrder(int numCourses, int prerequisites[][2], int prerequisitesSize, int *order) {
    int *indegree = calloc((size_t)numCourses, sizeof(int));
    int *outCount = calloc((size_t)numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; ++i) {
        ++outCount[prerequisites[i][1]];
        ++indegree[prerequisites[i][0]];
    }

    int **adj = malloc((size_t)numCourses * sizeof(int *));
    for (int i = 0; i < numCourses; ++i) {
        adj[i] = outCount[i] > 0
                 ? malloc((size_t)outCount[i] * sizeof(int))
                 : NULL;
    }
    memset(outCount, 0, (size_t)numCourses * sizeof(int));

    for (int i = 0; i < prerequisitesSize; ++i) {
        int a = prerequisites[i][0], b = prerequisites[i][1];
        adj[b][outCount[b]++] = a;
    }

    int *queue = malloc((size_t)numCourses * sizeof(int));
    int head = 0, tail = 0, used = 0;
    for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) queue[tail++] = i;
    }
    while (head < tail) {
        int u = queue[head++];
        order[used++] = u;
        for (int i = 0; i < outCount[u]; ++i) {
            int v = adj[u][i];
            if (--indegree[v] == 0) queue[tail++] = v;
        }
    }

    for (int i = 0; i < numCourses; ++i) free(adj[i]);
    free(adj); free(indegree); free(outCount); free(queue);
    return used == numCourses ? used : 0;
}

static void printOrder(int *order, int n) {
    putchar('[');
    for (int i = 0; i < n; ++i) {
        if (i) printf(", ");
        printf("%d", order[i]);
    }
    puts("]");
}

int main(void) {
    int order[4];
    int n;

    int p1[][2] = {{1, 0}};
    n = findOrder(2, p1, 1, order);
    printOrder(order, n);  // [0, 1]

    int p2[][2] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    n = findOrder(4, p2, 4, order);
    printOrder(order, n);  // [0, 1, 2, 3] or similar valid order

    n = findOrder(1, NULL, 0, order);
    printOrder(order, n);  // [0]

    int p4[][2] = {{1, 0}, {0, 1}};
    n = findOrder(2, p4, 2, order);
    printOrder(order, n);  // []
    return 0;
}
