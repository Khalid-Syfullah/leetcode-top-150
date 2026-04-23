public class FindIndexOfFirstOccurrence {

    public static int strStr(String haystack, String needle) {
        int n = haystack.length(), m = needle.length();
        if (m == 0) return 0;
        for (int i = 0; i + m <= n; i++) {
            if (haystack.regionMatches(i, needle, 0, m)) return i;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(strStr("sadbutsad", "sad"));   // 0
        System.out.println(strStr("leetcode", "leeto"));  // -1
        System.out.println(strStr("hello", "ll"));        // 2
    }
}
