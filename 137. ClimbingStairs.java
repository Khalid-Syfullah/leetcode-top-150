public class climbingStairs {

    public static int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }

        // dp[i] represents the number of ways to reach step i
        int[] dp = new int[n + 1];
        dp[0] = 1; // 1 way to be at step 0 (do nothing)
        dp[1] = 1; // 1 way to reach step 1 (1 step)

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }


        return dp[n];
    }

    public static void main(String[] args) {
        System.out.println(climbStairs(2)); // 2 (1+1, 2)
        System.out.println(climbStairs(3)); // 3 (1+1+1, 1+2, 2+1)
        System.out.println(climbStairs(4)); // 5 (1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2)
        System.out.println(climbStairs(5)); // 8
        System.out.println(climbStairs(9)); // 55
        System.out.println(climbStairs(10)); // 89
    }

}
