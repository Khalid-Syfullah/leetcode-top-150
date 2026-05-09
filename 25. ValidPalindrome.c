#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(const char *s) {
    int l = 0, r = (int)strlen(s) - 1;
    while (l < r) {
        while (l < r && !isalnum((unsigned char)s[l])) l++;
        while (l < r && !isalnum((unsigned char)s[r])) r--;
        if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r])) return false;
        l++; r--;
    }
    return true;
}

int main(void) {
    printf("%s\n", isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false"); /* true */
    printf("%s\n", isPalindrome("race a car") ? "true" : "false");                     /* false */
    printf("%s\n", isPalindrome(" ") ? "true" : "false");                              /* true */

    return 0;
}
