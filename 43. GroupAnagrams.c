#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRS  1000
#define MAX_LEN   100
#define BUCKETS   512

/* Sort a string's characters to get the anagram key */
static int cmp_char(const void *a, const void *b) {
    return (*(const char *)a - *(const char *)b);
}

static void sortedKey(const char *s, char *key) {
    strcpy(key, s);
    qsort(key, strlen(key), 1, cmp_char);
}

typedef struct {
    char  key[MAX_LEN];
    char  strs[MAX_STRS][MAX_LEN];
    int   count;
    int   used;
} Bucket;

static Bucket buckets[BUCKETS];

static unsigned int hashKey(const char *s) {
    unsigned int h = 5381;
    while (*s) h = h * 33 ^ (unsigned char)*s++;
    return h % BUCKETS;
}

static void groupAnagrams(const char **strs, int n) {
    /* Reset buckets */
    for (int i = 0; i < BUCKETS; i++) { buckets[i].used = 0; buckets[i].count = 0; }

    for (int i = 0; i < n; i++) {
        char key[MAX_LEN];
        sortedKey(strs[i], key);
        unsigned int h = hashKey(key);
        /* Linear probe */
        while (buckets[h].used && strcmp(buckets[h].key, key) != 0)
            h = (h + 1) % BUCKETS;
        if (!buckets[h].used) {
            strcpy(buckets[h].key, key);
            buckets[h].used = 1;
            buckets[h].count = 0;
        }
        strcpy(buckets[h].strs[buckets[h].count++], strs[i]);
    }

    /* Print all non-empty buckets */
    printf("[");
    int firstGroup = 1;
    for (int i = 0; i < BUCKETS; i++) {
        if (!buckets[i].used) continue;
        if (!firstGroup) printf(", ");
        firstGroup = 0;
        printf("[");
        for (int j = 0; j < buckets[i].count; j++) {
            if (j) printf(", ");
            printf("%s", buckets[i].strs[j]);
        }
        printf("]");
    }
    printf("]\n");
}

int main(void) {
    const char *w1[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(w1, 6);

    const char *w2[] = {""};
    groupAnagrams(w2, 1);

    const char *w3[] = {"a"};
    groupAnagrams(w3, 1);

    return 0;
}
