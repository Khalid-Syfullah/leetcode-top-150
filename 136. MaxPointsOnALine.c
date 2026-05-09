#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a == 0 ? 1 : a;
}

/* Simple hash map entry for slope string -> count */
#define MAP_SIZE 1024

typedef struct Entry {
    char key[32];
    int  count;
    struct Entry *next;
} Entry;

static Entry *table[MAP_SIZE];

static void mapClear(void) {
    for (int i = 0; i < MAP_SIZE; i++) {
        Entry *e = table[i];
        while (e) {
            Entry *next = e->next;
            free(e);
            e = next;
        }
        table[i] = NULL;
    }
}

static unsigned int hashStr(const char *s) {
    unsigned int h = 5381;
    while (*s) h = ((h << 5) + h) + (unsigned char)*s++;
    return h % MAP_SIZE;
}

/* Increment count for key and return new count */
static int mapIncrement(const char *key) {
    unsigned int h = hashStr(key);
    Entry *e = table[h];
    while (e) {
        if (strcmp(e->key, key) == 0) {
            e->count++;
            return e->count;
        }
        e = e->next;
    }
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    strncpy(newEntry->key, key, 31);
    newEntry->key[31] = '\0';
    newEntry->count = 1;
    newEntry->next = table[h];
    table[h] = newEntry;
    return 1;
}

int maxPoints(int points[][2], int n) {
    if (n == 0) return 0;
    if (n <= 2) return n;

    int globalMax = 1;

    for (int i = 0; i < n; i++) {
        mapClear();
        int duplicates = 0;
        int localMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                duplicates++;
                continue;
            }

            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            /* Canonical form: dx >= 0; if dx==0 then dy=1; if dy==0 then dx=1 */
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0) {
                dy = 1;
            } else if (dy == 0) {
                dx = 1;
            }

            char key[32];
            snprintf(key, sizeof(key), "%d/%d", dy, dx);
            int count = mapIncrement(key);
            if (count > localMax) localMax = count;
        }

        int candidate = localMax + duplicates + 1;
        if (candidate > globalMax) globalMax = candidate;
    }

    mapClear();
    return globalMax;
}

int main(void) {
    int points1[][2] = {{1, 1}, {2, 2}, {3, 3}};
    int points2[][2] = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

    printf("%d\n", maxPoints(points1, 3)); /* 3 */
    printf("%d\n", maxPoints(points2, 6)); /* 4 */
    return 0;
}
