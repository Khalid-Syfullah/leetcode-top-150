#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    if (x < 0) return false;

    int original = x;
    int reversed = 0;

    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return original == reversed;
}

int main(void) {
    puts(isPalindrome(121)   ? "true" : "false"); /* true */
    puts(isPalindrome(-121)  ? "true" : "false"); /* false */
    puts(isPalindrome(10)    ? "true" : "false"); /* false */
    puts(isPalindrome(0)     ? "true" : "false"); /* true */
    puts(isPalindrome(12321) ? "true" : "false"); /* true */
    return 0;
}
