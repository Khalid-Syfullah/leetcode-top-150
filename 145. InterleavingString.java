public class interleavingString {

    public static boolean isInterleave(String s1, String s2, String s3) {
       int m = s1.length(), n = s2.length();

        // Step 1: Length check
        if (m + n != s3.length()) return false;

        // Step 2: DP table
        boolean[][] dp = new boolean[m + 1][n + 1];

        // Step 3: Base case
        dp[0][0] = true;

          // Step 5: Fill first column (using only s1)
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && s1.charAt(i - 1) == s3.charAt(i - 1);
        }

        // Step 4: Fill first row (using only s2)
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
        }

        // Step 6: Fill the rest
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1) ||
                            dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1);
            }
        }

        // Step 7: Answer
        return dp[m][n];
    }

    public static void main(String[] args) {
        System.out.println(isInterleave("aaa", "aaa", "aaaaaa"));
        // System.out.println(isInterleave("aabcc", "dbbca", "aadbbcbcac")); // true
        // System.out.println(isInterleave("aabcc", "dbbca", "aadbbbaccc")); // false
        // System.out.println(isInterleave("", "", "")); // true
        // System.out.println(isInterleave("abc", "def", "adbcef")); // true
        // System.out.println(isInterleave("abc", "def", "abdecf")); // false
    }

}
