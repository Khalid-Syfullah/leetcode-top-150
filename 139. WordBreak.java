import java.util.*;

public class wordBreak {

	public static boolean isWordBreak(String s, List<String> wordDict) {
		if (s == null) return false;

		int n = s.length();

		Set<String> dict = new HashSet<>(wordDict);

		boolean[] dp = new boolean[n + 1];

		dp[0] = true;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] && dict.contains(s.substring(j, i))) {
					dp[i] = true;
					break;
				}
			}
		}

		return dp[n];
	}

	public static void main(String[] args) {
		System.out.println(isWordBreak("leetcode", Arrays.asList("leet", "code")));

		System.out.println(isWordBreak("applepenapple", Arrays.asList("apple", "pen")));

		System.out.println(isWordBreak("catsandog", Arrays.asList("cats","dog","sand","and","cat")));

		System.out.println(isWordBreak("", Arrays.asList("a")));

		System.out.println(isWordBreak("a", Arrays.asList()));
	}

}
