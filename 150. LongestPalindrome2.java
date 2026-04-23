public class longestPalindrome2 {

    public static String longestPalindromeSubstr(String s) {
     if(s == null || s.length() < 1){
            return "";
        }
        int start = 0, maxLen = 1;
        for(int i = 0; i < s.length(); i++){
            int[] odd = expand(s, i, i);
            int len = odd[1] - odd[0] + 1;
            if (len > maxLen){
                maxLen = len;
                start = odd[0];
            }

            int[] even = expand(s, i, i + 1);
            len = even[1] - even[0] + 1;
            if (len > maxLen){
                maxLen = len;
                start = even[0];
            }
        }

        return s.substring(start, start + maxLen);
        
    }

    public static int[] expand(String s, int left, int right){
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }
        return new int[]{left + 1, right - 1};

    }

    public static void main(String[] args) {
        System.out.println(longestPalindromeSubstr("babad")); // "bab" or "aba"
        System.out.println(longestPalindromeSubstr("cbbd"));   // "bb"
        System.out.println(longestPalindromeSubstr("a"));      // "a"
        System.out.println(longestPalindromeSubstr("ac"));     // "a" or "c"
        System.out.println(longestPalindromeSubstr("forgeeksskeegfor")); // "geeksskeeg"
    }

}
