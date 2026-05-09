#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(const char *s, int numRows) {
    int n = (int)strlen(s);
    char *out = malloc((size_t)n + 1);
    if (numRows == 1 || numRows >= n) {
        strcpy(out, s);
        return out;
    }

    /* Build each row as a dynamic buffer then concatenate */
    char **rows = calloc((size_t)numRows, sizeof(char *));
    int *rowLen = calloc((size_t)numRows, sizeof(int));
    for (int r = 0; r < numRows; r++) {
        rows[r] = malloc((size_t)n + 1);
        rowLen[r] = 0;
    }

    int cur = 0, dir = -1;
    for (int i = 0; i < n; i++) {
        rows[cur][rowLen[cur]++] = s[i];
        if (cur == 0 || cur == numRows - 1) dir = -dir;
        cur += dir;
    }

    int k = 0;
    for (int r = 0; r < numRows; r++) {
        for (int j = 0; j < rowLen[r]; j++) out[k++] = rows[r][j];
        free(rows[r]);
    }
    out[k] = '\0';
    free(rows);
    free(rowLen);

    return out;
}

int main(void) {
    char *r1 = convert("PAYPALISHIRING", 3);
    printf("%s\n", r1); /* PAHNAPLSIIGYIR */
    free(r1);

    char *r2 = convert("PAYPALISHIRING", 4);
    printf("%s\n", r2); /* PINALSIGYAHRPI */
    free(r2);

    char *r3 = convert("A", 1);
    printf("%s\n", r3); /* A */
    free(r3);

    return 0;
}
