#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Doubly linked list node */
typedef struct DNode {
    int key;
    int value;
    struct DNode *prev;
    struct DNode *next;
} DNode;

/* Simple hash map using chaining with array of buckets */
#define HASH_SIZE 1024

typedef struct HEntry {
    int key;
    DNode *node;
    struct HEntry *next;
} HEntry;

typedef struct {
    int capacity;
    int size;
    DNode *head; /* most recently used sentinel */
    DNode *tail; /* least recently used sentinel */
    HEntry *buckets[HASH_SIZE];
} LRUCache;

static int hashKey(int key) {
    unsigned int k = (unsigned int)key;
    return (int)(k % HASH_SIZE);
}

static DNode *newDNode(int key, int value) {
    DNode *n = malloc(sizeof(DNode));
    n->key = key;
    n->value = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

static void lruRemove(LRUCache *c, DNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

static void lruInsertToFront(LRUCache *c, DNode *node) {
    node->next = c->head->next;
    node->prev = c->head;
    c->head->next->prev = node;
    c->head->next = node;
}

static DNode *mapGet(LRUCache *c, int key) {
    int h = hashKey(key);
    HEntry *e = c->buckets[h];
    while (e != NULL) {
        if (e->key == key) return e->node;
        e = e->next;
    }
    return NULL;
}

static void mapPut(LRUCache *c, int key, DNode *node) {
    int h = hashKey(key);
    HEntry *e = c->buckets[h];
    while (e != NULL) {
        if (e->key == key) { e->node = node; return; }
        e = e->next;
    }
    HEntry *ne = malloc(sizeof(HEntry));
    ne->key = key;
    ne->node = node;
    ne->next = c->buckets[h];
    c->buckets[h] = ne;
}

static void mapRemove(LRUCache *c, int key) {
    int h = hashKey(key);
    HEntry *e = c->buckets[h];
    HEntry *prev = NULL;
    while (e != NULL) {
        if (e->key == key) {
            if (prev == NULL) c->buckets[h] = e->next;
            else prev->next = e->next;
            free(e);
            return;
        }
        prev = e;
        e = e->next;
    }
}

LRUCache *lruCreate(int capacity) {
    LRUCache *c = malloc(sizeof(LRUCache));
    c->capacity = capacity;
    c->size = 0;
    memset(c->buckets, 0, sizeof(c->buckets));
    c->head = newDNode(0, 0);
    c->tail = newDNode(0, 0);
    c->head->next = c->tail;
    c->tail->prev = c->head;
    return c;
}

int lruGet(LRUCache *c, int key) {
    DNode *node = mapGet(c, key);
    if (node == NULL) return -1;
    lruRemove(c, node);
    lruInsertToFront(c, node);
    return node->value;
}

void lruPut(LRUCache *c, int key, int value) {
    DNode *existing = mapGet(c, key);
    if (existing != NULL) {
        existing->value = value;
        lruRemove(c, existing);
        lruInsertToFront(c, existing);
        return;
    }

    if (c->size == c->capacity) {
        DNode *lru = c->tail->prev;
        lruRemove(c, lru);
        mapRemove(c, lru->key);
        free(lru);
        c->size--;
    }

    DNode *node = newDNode(key, value);
    mapPut(c, key, node);
    lruInsertToFront(c, node);
    c->size++;
}

int main(void) {
    LRUCache *cache = lruCreate(2);
    lruPut(cache, 1, 1);
    lruPut(cache, 2, 2);
    printf("%d\n", lruGet(cache, 1));  /* 1 */
    lruPut(cache, 3, 3);
    printf("%d\n", lruGet(cache, 2));  /* -1 */
    lruPut(cache, 4, 4);
    printf("%d\n", lruGet(cache, 1));  /* -1 */
    printf("%d\n", lruGet(cache, 3));  /* 3 */
    printf("%d\n", lruGet(cache, 4));  /* 4 */
    return 0;
}
