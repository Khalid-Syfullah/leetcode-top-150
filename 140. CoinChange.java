import java.util.Arrays;

public class coinChange {

    public static int minCoinChange(int[] coins, int amount) {
        if (amount < 1) return 0;

        int[] dp = new int[amount + 1];

        Arrays.fill(dp, amount + 1);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }

    public static void main(String[] args) {
        System.out.println(minCoinChange(new int[]{1, 2, 5}, 11));

        System.out.println(minCoinChange(new int[]{2}, 3));

        System.out.println(minCoinChange(new int[]{1}, 0));

        System.out.println(minCoinChange(new int[]{1, 2, 5}, 100));

        System.out.println(minCoinChange(new int[]{3, 7}, 4));
    }

}
