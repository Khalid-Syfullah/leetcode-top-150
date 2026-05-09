#include <stdbool.h>
#include <stdio.h>

static int nextHappy(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = nextHappy(n);
    while (fast != 1 && slow != fast) {
        slow = nextHappy(slow);
        fast = nextHappy(nextHappy(fast));
    }
    return fast == 1;
}

int main(void) {
    puts(isHappy(19) ? "true" : "false"); // true
    puts(isHappy(2)  ? "true" : "false"); // false
    puts(isHappy(1)  ? "true" : "false"); // true
    return 0;
}
