#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* Open-addressing hash map: val -> index in list */
#define HT_SIZE 1024

typedef struct {
    int key;
    int val;
    bool used;
} HEntry;

typedef struct {
    int *list;
    int size;
    int capacity;
    HEntry table[HT_SIZE];
} RandomizedSet;

static int htHash(int key) {
    unsigned int h = (unsigned int)key;
    h ^= h >> 16;
    h *= 0x45d9f3b;
    h ^= h >> 16;
    return (int)(h % HT_SIZE);
}

static void htPut(HEntry *table, int key, int val) {
    int h = htHash(key);
    while (table[h].used && table[h].key != key) h = (h + 1) % HT_SIZE;
    table[h].key = key;
    table[h].val = val;
    table[h].used = true;
}

static int htGet(HEntry *table, int key, bool *found) {
    int h = htHash(key);
    while (table[h].used) {
        if (table[h].key == key) { *found = true; return table[h].val; }
        h = (h + 1) % HT_SIZE;
    }
    *found = false;
    return -1;
}

static void htRemove(HEntry *table, int key) {
    int h = htHash(key);
    while (table[h].used && table[h].key != key) h = (h + 1) % HT_SIZE;
    if (!table[h].used) return;
    table[h].used = false;
    /* Rehash subsequent entries */
    int next = (h + 1) % HT_SIZE;
    while (table[next].used) {
        HEntry e = table[next];
        table[next].used = false;
        htPut(table, e.key, e.val);
        next = (next + 1) % HT_SIZE;
    }
}

static RandomizedSet *rsCreate(void) {
    RandomizedSet *rs = calloc(1, sizeof(RandomizedSet));
    rs->capacity = 16;
    rs->list = malloc((size_t)rs->capacity * sizeof(int));
    return rs;
}

static bool rsInsert(RandomizedSet *rs, int val) {
    bool found;
    htGet(rs->table, val, &found);
    if (found) return false;
    if (rs->size == rs->capacity) {
        rs->capacity *= 2;
        rs->list = realloc(rs->list, (size_t)rs->capacity * sizeof(int));
    }
    rs->list[rs->size] = val;
    htPut(rs->table, val, rs->size);
    rs->size++;
    return true;
}

static bool rsRemove(RandomizedSet *rs, int val) {
    bool found;
    int idx = htGet(rs->table, val, &found);
    if (!found) return false;
    int last = rs->size - 1;
    if (idx != last) {
        int lv = rs->list[last];
        rs->list[idx] = lv;
        htPut(rs->table, lv, idx);
    }
    rs->size--;
    htRemove(rs->table, val);
    return true;
}

static int rsGetRandom(RandomizedSet *rs) {
    int idx = rand() % rs->size;
    return rs->list[idx];
}

static void rsFree(RandomizedSet *rs) {
    free(rs->list);
    free(rs);
}

int main(void) {
    srand((unsigned int)time(NULL));
    RandomizedSet *s = rsCreate();

    printf("%s\n", rsInsert(s, 1) ? "true" : "false");  /* true */
    printf("%s\n", rsRemove(s, 2) ? "true" : "false");  /* false */
    printf("%s\n", rsInsert(s, 2) ? "true" : "false");  /* true */
    printf("%d\n", rsGetRandom(s));                      /* 1 or 2 */
    printf("%s\n", rsRemove(s, 1) ? "true" : "false");  /* true */
    printf("%s\n", rsInsert(s, 2) ? "true" : "false");  /* false */
    printf("%d\n", rsGetRandom(s));                      /* 2 */

    rsFree(s);
    return 0;
}
