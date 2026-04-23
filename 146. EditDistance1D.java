public class EditDistance1D {

    /**
     * Calculates the minimum edit distance (Levenshtein distance) between two strings.
     * This is a space-optimized version using O(n) space instead of O(m*n).
     * 
     * @param word1 the first string
     * @param word2 the second string
     * @return the minimum number of operations (insert, delete, replace) to transform word1 into word2
     */
    public static int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();

        // dp[j] will represent the edit distance between word1[0..i-1] and word2[0..j-1]
        // at the end of each outer loop iteration (for current i)
        int[] dp = new int[n + 1];

        // Initialize dp array: dp[j] = j means it takes j insertions to transform
        // empty string "" to word2[0..j-1]
        for (int j = 0; j <= n; j++){
            dp[j] = j;
        }

        // Process each character of word1
        for (int i = 1; i <= m; i++){
            // 'prev' will store the value that would be dp[j-1] from the previous row
            // (the diagonal value in 2D DP terms)
            int prev = i - 1;
            
            // Set dp[0] = i: it takes i deletions to transform word1[0..i-1] to empty string
            dp[0] = i;

            // Process each character of word2 for this row
            for (int j = 1; j <= n; j++){
                // Save the current dp[j] before we overwrite it
                // This represents the "up" value (delete operation) in 2D DP
                int temp = dp[j];

                if (word1.charAt(i - 1) == word2.charAt(j - 1)){
                    // Characters match: no operation needed
                    // Use the diagonal value (prev, which is dp[j-1] from previous row)
                    dp[j] = prev;
                }
                else {
                    // Characters don't match: choose minimum of three operations:
                    // 1. Replace: prev (diagonal, represents replace)
                    // 2. Delete: temp (up, current dp[j] represents delete from word1)
                    // 3. Insert: dp[j-1] (left, represents insert into word1)
                    dp[j] = 1 + Math.min(prev, Math.min(temp, dp[j - 1]));
                }

                // Update prev for next iteration: it becomes the "diagonal" for j+1
                prev = temp;
            }
        }

        // dp[n] now contains the edit distance between full word1 and word2
        return dp[n];
    }

    public static void main(String[] args) {
        System.out.println(minDistance("horse", "ros")); // Expected: 3
        System.out.println(minDistance("intention", "execution")); // Expected: 5
        System.out.println(minDistance("", "a")); // Expected: 1
        System.out.println(minDistance("a", "a")); // Expected: 0
        System.out.println(minDistance("abc", "def")); // Expected: 3
    }
    
}

