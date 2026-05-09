#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 50
#define MAX_EDGES 200

/* Simple string-to-index mapping */
static char varNames[MAX_VARS][16];
static int  varCount = 0;

static int getOrAdd(const char *name) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(varNames[i], name) == 0) return i;
    }
    strncpy(varNames[varCount], name, 15);
    varNames[varCount][15] = '\0';
    return varCount++;
}

static int getId(const char *name) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(varNames[i], name) == 0) return i;
    }
    return -1;
}

/* Adjacency list */
typedef struct {
    int to;
    double weight;
} Edge;

static Edge adjList[MAX_VARS][MAX_EDGES];
static int  adjCount[MAX_VARS];

static void addEdge(int from, int to, double weight) {
    adjList[from][adjCount[from]].to     = to;
    adjList[from][adjCount[from]].weight = weight;
    adjCount[from]++;
}

static int visitedDFS[MAX_VARS];

static double dfs(int cur, int target, double product) {
    if (cur == target) return product;
    visitedDFS[cur] = 1;
    for (int i = 0; i < adjCount[cur]; i++) {
        int nb = adjList[cur][i].to;
        if (visitedDFS[nb]) continue;
        double ans = dfs(nb, target, product * adjList[cur][i].weight);
        if (ans != -1.0) return ans;
    }
    return -1.0;
}

/* equations: array of pairs of strings; equLen = number of equations */
void buildGraph(const char equations[][2][16], int equLen, const double values[]) {
    varCount = 0;
    memset(adjCount, 0, sizeof(adjCount));
    for (int i = 0; i < equLen; i++) {
        int a = getOrAdd(equations[i][0]);
        int b = getOrAdd(equations[i][1]);
        addEdge(a, b, values[i]);
        addEdge(b, a, 1.0 / values[i]);
    }
}

double calcEquationQuery(const char *src, const char *dst) {
    int s = getId(src);
    int t = getId(dst);
    if (s == -1 || t == -1) return -1.0;
    if (s == t) return 1.0;
    memset(visitedDFS, 0, sizeof(visitedDFS));
    return dfs(s, t, 1.0);
}

int main(void) {
    /* Test 1 */
    const char eq1[][2][16] = {{"a","b"}, {"b","c"}};
    double val1[] = {2.0, 3.0};
    buildGraph(eq1, 2, val1);

    const char *queries1[][2] = {
        {"a","c"}, {"b","a"}, {"a","e"}, {"a","a"}, {"x","x"}
    };
    int q1len = 5;
    printf("[");
    for (int i = 0; i < q1len; i++) {
        if (i) printf(", ");
        double r = calcEquationQuery(queries1[i][0], queries1[i][1]);
        printf("%.1f", r);
    }
    puts("]");

    /* Test 2 */
    const char eq2[][2][16] = {{"a","b"}, {"b","c"}, {"bc","cd"}};
    double val2[] = {1.5, 2.5, 5.0};
    buildGraph(eq2, 3, val2);

    const char *queries2[][2] = {
        {"a","c"}, {"c","b"}, {"bc","cd"}, {"cd","bc"}
    };
    int q2len = 4;
    printf("[");
    for (int i = 0; i < q2len; i++) {
        if (i) printf(", ");
        double r = calcEquationQuery(queries2[i][0], queries2[i][1]);
        printf("%.1f", r);
    }
    puts("]");

    return 0;
}
