public class IsomorphicStrings {

    public static boolean isIsomorphic(String s, String t) {
        int[] ms = new int[256], mt = new int[256];
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i), b = t.charAt(i);
            if (ms[a] != mt[b]) return false;
            ms[a] = mt[b] = i + 1;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isIsomorphic("egg", "add"));     // true
        System.out.println(isIsomorphic("foo", "bar"));     // false
        System.out.println(isIsomorphic("paper", "title")); // true
    }
}
