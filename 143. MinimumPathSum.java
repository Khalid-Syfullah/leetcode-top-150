public class minimumPathSum {

    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // Step 1: Create DP table
        int[][] dp = new int[m][n];

        // Step 2: Initialize starting cell
        dp[0][0] = grid[0][0];

         // Step 3: Fill first column (can only come from above)
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Step 4: Fill first row (can only come from the left)
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Step 5: Fill the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 6: Return bottom-right cell
        return dp[m - 1][n - 1];
    }

    public static void main(String[] args) {
        minimumPathSum sol = new minimumPathSum();

        int[][] grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        System.out.println("Example 1: " + sol.minPathSum(grid1)); // 7

        int[][] grid2 = {{1, 2, 3}, {4, 5, 6}};
        System.out.println("Example 2: " + sol.minPathSum(grid2)); // 12
    }
}