public class HappyNumber {

    public static boolean isHappy(int n) {
        int slow = n, fast = next(n);
        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }

    private static int next(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(isHappy(19)); // true
        System.out.println(isHappy(2));  // false
        System.out.println(isHappy(1));  // true
    }
}
