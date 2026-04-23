#include <stdbool.h>
#include <stdio.h>

static int nextNum(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = nextNum(n);
    while (fast != 1 && slow != fast) {
        slow = nextNum(slow);
        fast = nextNum(nextNum(fast));
    }
    return fast == 1;
}

int main(void) {
    puts(isHappy(19) ? "true" : "false");
    return 0;
}
