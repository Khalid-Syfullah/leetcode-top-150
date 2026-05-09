#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    bool val;
    bool isLeaf;
    struct Node *topLeft;
    struct Node *topRight;
    struct Node *bottomLeft;
    struct Node *bottomRight;
};

static struct Node *newNode(bool val, bool isLeaf) {
    struct Node *node = malloc(sizeof(*node));
    node->val = val;
    node->isLeaf = isLeaf;
    node->topLeft = node->topRight = node->bottomLeft = node->bottomRight = NULL;
    return node;
}

static bool isUniform(int grid[][4], int row, int col, int size) {
    int value = grid[row][col];
    for (int r = row; r < row + size; r++) {
        for (int c = col; c < col + size; c++) {
            if (grid[r][c] != value) return false;
        }
    }
    return true;
}

static struct Node *buildQuad(int grid[][4], int row, int col, int size) {
    if (isUniform(grid, row, col, size)) {
        return newNode(grid[row][col] == 1, true);
    }
    int half = size / 2;
    struct Node *node = newNode(true, false);
    node->topLeft     = buildQuad(grid, row,        col,        half);
    node->topRight    = buildQuad(grid, row,        col + half, half);
    node->bottomLeft  = buildQuad(grid, row + half, col,        half);
    node->bottomRight = buildQuad(grid, row + half, col + half, half);
    return node;
}

static struct Node *construct(int grid[][4], int n) {
    return buildQuad(grid, 0, 0, n);
}

static void printPreorder(struct Node *root) {
    if (root == NULL) return;
    if (root->isLeaf) {
        printf("[Leaf:%d] ", root->val ? 1 : 0);
        return;
    }
    printf("[Parent] ");
    printPreorder(root->topLeft);
    printPreorder(root->topRight);
    printPreorder(root->bottomLeft);
    printPreorder(root->bottomRight);
}

int main(void) {
    int grid[4][4] = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0}
    };
    struct Node *root = construct(grid, 4);
    printPreorder(root);
    printf("\n");
    return 0;
}
