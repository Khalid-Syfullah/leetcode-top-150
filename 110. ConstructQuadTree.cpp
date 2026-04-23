#include <iostream>
#include <vector>
using namespace std;

struct Node {
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool val, bool isLeaf) : val(val), isLeaf(isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool val, bool isLeaf, Node* topLeft, Node* topRight, Node* bottomLeft, Node* bottomRight)
        : val(val), isLeaf(isLeaf), topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight) {}
};

bool isUniform(vector<vector<int>>& grid, int row, int col, int size) {
    int value = grid[row][col];
    for (int r = row; r < row + size; r++) {
        for (int c = col; c < col + size; c++) {
            if (grid[r][c] != value) return false;
        }
    }
    return true;
}

Node* build(vector<vector<int>>& grid, int row, int col, int size) {
    if (isUniform(grid, row, col, size)) {
        return new Node(grid[row][col] == 1, true);
    }
    int half = size / 2;
    Node* topLeft = build(grid, row, col, half);
    Node* topRight = build(grid, row, col + half, half);
    Node* bottomLeft = build(grid, row + half, col, half);
    Node* bottomRight = build(grid, row + half, col + half, half);
    return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
}

Node* construct(vector<vector<int>>& grid) {
    return build(grid, 0, 0, grid.size());
}

void printPreorder(Node* root) {
    if (!root) return;
    if (root->isLeaf) {
        cout << "[Leaf:" << (root->val ? 1 : 0) << "] ";
        return;
    }
    cout << "[Parent] ";
    printPreorder(root->topLeft);
    printPreorder(root->topRight);
    printPreorder(root->bottomLeft);
    printPreorder(root->bottomRight);
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0}
    };
    Node* root = construct(grid);
    printPreorder(root);
    cout << "\n";
    return 0;
}
