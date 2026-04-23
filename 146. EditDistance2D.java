public class EditDistance2D {

    public static int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();

        // dp[i][j] = minimum edit distance to convert word1[0..i-1] to word2[0..j-1]
        int[][] dp = new int[m + 1][n + 1];

        // Base case: convert word1 prefix to empty string via deletion
        // dp[i][0] = i
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        // Base case: convert empty string to word2 prefix via insertion
        // dp[0][j] = j
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        // Fill the DP table for full ranges i=1..m, j=1..n
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    // when characters match, no new operation needed,
                    // take diagonal (previous state)
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 3 possible operations:
                    // replace: dp[i-1][j-1]
                    // delete from word1: dp[i-1][j]
                    // insert into word1: dp[i][j-1]
                    dp[i][j] = 1 + Math.min(
                        dp[i - 1][j - 1],
                        Math.min(dp[i - 1][j], dp[i][j - 1])
                    );
                }
            }
        }

        // Final answer: full words
        return dp[m][n];    
    }

    public static void main(String[] args) {
        System.out.println(minDistance("horse", "ros")); // 3
        System.out.println(minDistance("intention", "execution")); // 5
        System.out.println(minDistance("", "a")); // 1
        System.out.println(minDistance("a", "a")); // 0
        System.out.println(minDistance("abc", "def")); // 3
    }
}