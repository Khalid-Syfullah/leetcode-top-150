public class climbingStairs2 {
   
    public static int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }


    public static void main(String[] args) {
        System.out.println(climbStairs(2)); // 2 (1+1, 2)
        System.out.println(climbStairs(3)); // 3 (1+1+1, 1+2, 2+1)
        System.out.println(climbStairs(4)); // 5 (1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2)
        System.out.println(climbStairs(5)); // 8
        System.out.println(climbStairs(9)); // 1
        System.out.println(climbStairs(10)); // 1
    }
}
