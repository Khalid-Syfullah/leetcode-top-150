#include <stdio.h>
#include <string.h>

char *convert(const char *s, int numRows) {
    static char out[2048];
    int n = (int)strlen(s), k = 0;
    if (numRows == 1 || numRows >= n) {
        strcpy(out, s);
        return out;
    }
    int cycle = 2 * numRows - 2;
    for (int row = 0; row < numRows; ++row) {
        for (int j = row; j < n; j += cycle) {
            out[k++] = s[j];
            int diag = j + cycle - 2 * row;
            if (row != 0 && row != numRows - 1 && diag < n) out[k++] = s[diag];
        }
    }
    out[k] = '\0';
    return out;
}

int main(void) {
    puts(convert("PAYPALISHIRING", 3));
    return 0;
}
