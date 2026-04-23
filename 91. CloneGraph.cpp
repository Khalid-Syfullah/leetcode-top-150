#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int val) : val(val) {}
    Node(int val, vector<Node*> neighbors) : val(val), neighbors(neighbors) {}
};

Node* dfs(Node* node, unordered_map<Node*, Node*>& clones) {
    if (clones.count(node)) {
        return clones[node];
    }
    Node* copy = new Node(node->val);
    clones[node] = copy;
    for (Node* neighbor : node->neighbors) {
        copy->neighbors.push_back(dfs(neighbor, clones));
    }
    return copy;
}

Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    unordered_map<Node*, Node*> clones;
    return dfs(node, clones);
}

void printDfs(Node* node, unordered_map<Node*, bool>& visited) {
    if (node == nullptr || visited.count(node)) return;
    visited[node] = true;
    cout << "Node " << node->val << " -> ";
    for (Node* n : node->neighbors) {
        cout << n->val << " ";
    }
    cout << "\n";
    for (Node* n : node->neighbors) {
        printDfs(n, visited);
    }
}

void printGraph(Node* node) {
    unordered_map<Node*, bool> visited;
    printDfs(node, visited);
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);

    Node* clone = cloneGraph(n1);

    printGraph(n1);
    cout << "---\n";
    printGraph(clone);
    return 0;
}
