import java.util.HashMap;
import java.util.Map;

public class WordPattern {

    public static boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (words.length != pattern.length()) return false;
        Map<Character, String> cToW = new HashMap<>();
        Map<String, Character> wToC = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String w = words[i];
            if (cToW.containsKey(c) && !cToW.get(c).equals(w)) return false;
            if (wToC.containsKey(w) && wToC.get(w) != c) return false;
            cToW.put(c, w);
            wToC.put(w, c);
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(wordPattern("abba", "dog cat cat dog")); // true
        System.out.println(wordPattern("abba", "dog cat cat fish"));// false
        System.out.println(wordPattern("aaaa", "dog cat cat dog")); // false
    }
}
