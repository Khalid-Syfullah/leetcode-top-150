#include <stdio.h>
#include <string.h>

int lengthOfLastWord(const char *s) {
    int i = (int)strlen(s) - 1, len = 0;
    while (i >= 0 && s[i] == ' ') i--;
    while (i >= 0 && s[i] != ' ') { len++; i--; }
    return len;
}

int main(void) {
    printf("%d\n", lengthOfLastWord("Hello World"));               /* 5 */
    printf("%d\n", lengthOfLastWord("   fly me   to   the moon ")); /* 4 */
    printf("%d\n", lengthOfLastWord("luffy is still joyboy"));      /* 6 */

    return 0;
}
