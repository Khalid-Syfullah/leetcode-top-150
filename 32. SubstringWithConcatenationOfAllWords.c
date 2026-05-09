#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 200
#define WORD_LEN  32

/* Simple hash map: string -> int count, using open addressing */
#define HT_SIZE 512

typedef struct {
    char key[WORD_LEN];
    int  val;
    int  used;
} HTEntry;

static unsigned int hash_str(const char *s) {
    unsigned int h = 5381;
    while (*s) h = h * 33 ^ (unsigned char)*s++;
    return h % HT_SIZE;
}

static void ht_clear(HTEntry *ht) {
    memset(ht, 0, HT_SIZE * sizeof(HTEntry));
}

static int ht_get(HTEntry *ht, const char *key) {
    unsigned int h = hash_str(key);
    while (ht[h].used) {
        if (strcmp(ht[h].key, key) == 0) return ht[h].val;
        h = (h + 1) % HT_SIZE;
    }
    return 0;
}

static void ht_add(HTEntry *ht, const char *key, int delta) {
    unsigned int h = hash_str(key);
    while (ht[h].used && strcmp(ht[h].key, key) != 0)
        h = (h + 1) % HT_SIZE;
    if (!ht[h].used) { strncpy(ht[h].key, key, WORD_LEN - 1); ht[h].used = 1; }
    ht[h].val += delta;
}

/* Returns indices in res[], sets *resSize */
void findSubstring(const char *s, const char **words, int k,
                   int *res, int *resSize) {
    *resSize = 0;
    if (k == 0) return;
    int slen = (int)strlen(s);
    int w = (int)strlen(words[0]);
    int total = w * k;
    if (slen < total) return;

    HTEntry need[HT_SIZE];
    ht_clear(need);
    for (int i = 0; i < k; i++) ht_add(need, words[i], 1);

    char buf[WORD_LEN];

    for (int i = 0; i < w; i++) {
        HTEntry seen[HT_SIZE];
        ht_clear(seen);
        int l = i, count = 0;
        for (int r = i; r + w <= slen; r += w) {
            strncpy(buf, s + r, (size_t)w);
            buf[w] = '\0';
            if (ht_get(need, buf) == 0) {
                ht_clear(seen);
                count = 0;
                l = r + w;
                continue;
            }
            ht_add(seen, buf, 1);
            count++;
            while (ht_get(seen, buf) > ht_get(need, buf)) {
                char left[WORD_LEN];
                strncpy(left, s + l, (size_t)w);
                left[w] = '\0';
                ht_add(seen, left, -1);
                l += w;
                count--;
            }
            if (count == k) res[(*resSize)++] = l;
        }
    }
}

static int cmp_int(const void *a, const void *b) {
    return (*(const int *)a - *(const int *)b);
}

int main(void) {
    int res[1000], sz;

    const char *w1[] = {"foo", "bar"};
    findSubstring("barfoothefoobarman", w1, 2, res, &sz);
    qsort(res, (size_t)sz, sizeof(int), cmp_int);
    printf("[");
    for (int i = 0; i < sz; i++) { if (i) printf(", "); printf("%d", res[i]); }
    printf("]\n"); // [0, 9]

    const char *w2[] = {"word", "good", "best", "word"};
    findSubstring("wordgoodgoodgoodbestword", w2, 4, res, &sz);
    qsort(res, (size_t)sz, sizeof(int), cmp_int);
    printf("[");
    for (int i = 0; i < sz; i++) { if (i) printf(", "); printf("%d", res[i]); }
    printf("]\n"); // []

    const char *w3[] = {"bar", "foo", "the"};
    findSubstring("barfoofoobarthefoobarman", w3, 3, res, &sz);
    qsort(res, (size_t)sz, sizeof(int), cmp_int);
    printf("[");
    for (int i = 0; i < sz; i++) { if (i) printf(", "); printf("%d", res[i]); }
    printf("]\n"); // [6, 9, 12]

    return 0;
}
