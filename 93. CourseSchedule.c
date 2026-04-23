#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool canFinish(int numCourses, int prerequisites[][2], int prerequisitesSize) {
    int *indegree = calloc((size_t)numCourses, sizeof(int));
    int *outCount = calloc((size_t)numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; ++i) {
        ++outCount[prerequisites[i][1]];
        ++indegree[prerequisites[i][0]];
    }
    int **adj = malloc((size_t)numCourses * sizeof(int *));
    for (int i = 0; i < numCourses; ++i) adj[i] = malloc((size_t)outCount[i] * sizeof(int));
    for (int i = 0; i < numCourses; ++i) outCount[i] = 0;
    for (int i = 0; i < prerequisitesSize; ++i) {
        int a = prerequisites[i][0], b = prerequisites[i][1];
        adj[b][outCount[b]++] = a;
    }
    int *queue = malloc((size_t)numCourses * sizeof(int));
    int head = 0, tail = 0, seen = 0;
    for (int i = 0; i < numCourses; ++i) if (indegree[i] == 0) queue[tail++] = i;
    while (head < tail) {
        int u = queue[head++];
        ++seen;
        for (int i = 0; i < outCount[u]; ++i) {
            int v = adj[u][i];
            if (--indegree[v] == 0) queue[tail++] = v;
        }
    }
    for (int i = 0; i < numCourses; ++i) free(adj[i]);
    free(adj);
    free(indegree);
    free(outCount);
    free(queue);
    return seen == numCourses;
}

int main(void) {
    int p[][2] = {{1, 0}};
    puts(canFinish(2, p, 1) ? "true" : "false");
    return 0;
}
