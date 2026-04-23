#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int rev = 0;
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return x == rev || x == rev / 10;
}

int main(void) {
    puts(isPalindrome(121) ? "true" : "false");
    return 0;
}
