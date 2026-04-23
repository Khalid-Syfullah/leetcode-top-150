import java.util.Arrays;

public class maxProfitIV {

	public static int maxProfit(int k, int[] prices) {
		 int n = prices.length;
        if (k == 0 || n == 0) {
            return 0;
        }

        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++){
                
                if (prices[i] > prices[i - 1]){
                    profit += prices[i] - prices[i - 1];
                }
            }

            return profit;
            
        }

        int[][] dp = new int[k+1][n];

        for (int i = 1; i <= k; i++){
            int localMax = -prices[0];

            for (int j = 1; j < n; j++){
                dp[i][j] = Math.max(dp[i][j-1], localMax + prices[j]);
                localMax = Math.max(localMax, dp[i-1][j] - prices[j]);
            }
        }

        return dp[k][n-1];
	}

	public static void main(String[] args) {
		// sample tests
		int[] prices1 = {2, 4, 1};
		System.out.println(maxProfit(2, prices1)); // expected 2

		int[] prices2 = {3,2,6,5,0,3};
		System.out.println(maxProfit(2, prices2)); // expected 7

		int[] prices3 = {1,2,3,4,5};
		System.out.println(maxProfit(2, prices3)); // expected 4

		int[] prices4 = {7,6,4,3,1};
		System.out.println(maxProfit(2, prices4)); // expected 0
	}

}
