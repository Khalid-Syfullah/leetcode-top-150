#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    int capacity;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        Node* node = it->second;
        remove(node);
        insertToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            Node* existing = it->second;
            existing->value = value;
            remove(existing);
            insertToFront(existing);
            return;
        }
        if ((int)map.size() == capacity) {
            Node* lru = tail->prev;
            remove(lru);
            map.erase(lru->key);
            delete lru;
        }
        Node* node = new Node(key, value);
        map[key] = node;
        insertToFront(node);
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n";
    cache.put(3, 3);
    cout << cache.get(2) << "\n";
    cache.put(4, 4);
    cout << cache.get(1) << "\n";
    cout << cache.get(3) << "\n";
    cout << cache.get(4) << "\n";
    return 0;
}
