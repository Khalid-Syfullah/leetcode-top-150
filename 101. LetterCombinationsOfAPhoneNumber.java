import java.util.ArrayList;
import java.util.List;

public class LetterCombinationsOfAPhoneNumber {

    private static final String[] MAP = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    public static List<String> letterCombinations(String digits) {
        List<String> out = new ArrayList<>();
        if (digits.isEmpty()) return out;
        dfs(digits, 0, new StringBuilder(), out);
        return out;
    }

    private static void dfs(String digits, int i, StringBuilder cur, List<String> out) {
        if (i == digits.length()) {
            out.add(cur.toString());
            return;
        }
        for (char c : MAP[digits.charAt(i) - '0'].toCharArray()) {
            cur.append(c);
            dfs(digits, i + 1, cur, out);
            cur.deleteCharAt(cur.length() - 1);
        }
    }

    public static void main(String[] args) {
        System.out.println(letterCombinations("23")); // [ad, ae, af, bd, be, bf, cd, ce, cf]
        System.out.println(letterCombinations(""));   // []
        System.out.println(letterCombinations("2"));  // [a, b, c]
    }
}
