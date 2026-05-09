#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 101
#define MAX_NEIGHBORS 100

typedef struct Node {
    int val;
    struct Node *neighbors[MAX_NEIGHBORS];
    int neighborCount;
} Node;

/* Global clone map indexed by node value (1..100) */
static Node *cloneMap[MAX_NODES];

Node *newGraphNode(int val) {
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->val = val;
    node->neighborCount = 0;
    return node;
}

Node *dfs(Node *node) {
    if (!node) return NULL;
    if (cloneMap[node->val]) return cloneMap[node->val];

    Node *copy = newGraphNode(node->val);
    cloneMap[node->val] = copy;

    for (int i = 0; i < node->neighborCount; i++) {
        copy->neighbors[copy->neighborCount++] = dfs(node->neighbors[i]);
    }
    return copy;
}

Node *cloneGraph(Node *node) {
    if (!node) return NULL;
    memset(cloneMap, 0, sizeof(cloneMap));
    return dfs(node);
}

static int visited[MAX_NODES];

static void printDfs(Node *node) {
    if (!node || visited[node->val]) return;
    visited[node->val] = 1;
    printf("Node %d -> ", node->val);
    for (int i = 0; i < node->neighborCount; i++) {
        printf("%d ", node->neighbors[i]->val);
    }
    printf("\n");
    for (int i = 0; i < node->neighborCount; i++) {
        printDfs(node->neighbors[i]);
    }
}

static void printGraph(Node *node) {
    memset(visited, 0, sizeof(visited));
    printDfs(node);
}

int main(void) {
    Node *n1 = newGraphNode(1);
    Node *n2 = newGraphNode(2);
    Node *n3 = newGraphNode(3);
    Node *n4 = newGraphNode(4);

    n1->neighbors[n1->neighborCount++] = n2;
    n1->neighbors[n1->neighborCount++] = n4;
    n2->neighbors[n2->neighborCount++] = n1;
    n2->neighbors[n2->neighborCount++] = n3;
    n3->neighbors[n3->neighborCount++] = n2;
    n3->neighbors[n3->neighborCount++] = n4;
    n4->neighbors[n4->neighborCount++] = n1;
    n4->neighbors[n4->neighborCount++] = n3;

    Node *clone = cloneGraph(n1);

    printGraph(n1);
    puts("---");
    printGraph(clone);
    return 0;
}
