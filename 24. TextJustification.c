#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * fullJustify: given an array of words and a maxWidth, return lines of
 * full-justified text. Matches the Java implementation exactly.
 */
static char **fullJustify(const char **words, int wordsSize, int maxWidth, int *returnSize) {
    int n = wordsSize;
    /* Upper bound on number of lines = number of words */
    char **result = malloc((size_t)n * sizeof(char *));
    int lineCount = 0;
    int i = 0;

    while (i < n) {
        /* Determine how many words fit on this line */
        int j = i;
        int len = 0;
        while (j < n && len + (int)strlen(words[j]) + (j - i) <= maxWidth) {
            len += (int)strlen(words[j]);
            j++;
        }
        /* words[i..j-1] go on this line, total char count = len */
        char *line = malloc((size_t)maxWidth + 1);
        int pos = 0;
        int gaps = j - i - 1;

        if (j == n || gaps == 0) {
            /* Last line or single-word line: left-justify, pad right with spaces */
            for (int k = i; k < j; k++) {
                int wlen = (int)strlen(words[k]);
                memcpy(line + pos, words[k], (size_t)wlen);
                pos += wlen;
                if (k < j - 1) line[pos++] = ' ';
            }
            while (pos < maxWidth) line[pos++] = ' ';
        } else {
            /* Full justification */
            int spaces = (maxWidth - len) / gaps;
            int extra = (maxWidth - len) % gaps;
            for (int k = i; k < j; k++) {
                int wlen = (int)strlen(words[k]);
                memcpy(line + pos, words[k], (size_t)wlen);
                pos += wlen;
                if (k < j - 1) {
                    int sp = spaces + (k - i < extra ? 1 : 0);
                    for (int s = 0; s < sp; s++) line[pos++] = ' ';
                }
            }
        }
        line[pos] = '\0';
        result[lineCount++] = line;
        i = j;
    }

    *returnSize = lineCount;
    return result;
}

/* Print list in Java ArrayList.toString() format: [elem1, elem2, ...] */
static void printList(char **lines, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i) printf(", ");
        printf("%s", lines[i]);
    }
    printf("]\n");
}

int main(void) {
    const char *words1[] = {"This", "is", "an", "example", "of", "text", "justification."};
    int rsize1;
    char **r1 = fullJustify(words1, 7, 16, &rsize1);
    printList(r1, rsize1);
    for (int i = 0; i < rsize1; i++) free(r1[i]);
    free(r1);

    const char *words2[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int rsize2;
    char **r2 = fullJustify(words2, 6, 16, &rsize2);
    printList(r2, rsize2);
    for (int i = 0; i < rsize2; i++) free(r2[i]);
    free(r2);

    return 0;
}
