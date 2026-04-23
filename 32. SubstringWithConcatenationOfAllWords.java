import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SubstringWithConcatenationOfAllWords {

    public static List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        int w = words[0].length(), k = words.length, total = w * k;
        if (s.length() < total) return res;
        Map<String, Integer> need = new HashMap<>();
        for (String word : words) need.merge(word, 1, Integer::sum);
        for (int i = 0; i < w; i++) {
            int l = i, count = 0;
            Map<String, Integer> seen = new HashMap<>();
            for (int r = i; r + w <= s.length(); r += w) {
                String word = s.substring(r, r + w);
                if (!need.containsKey(word)) {
                    seen.clear();
                    count = 0;
                    l = r + w;
                    continue;
                }
                seen.merge(word, 1, Integer::sum);
                count++;
                while (seen.get(word) > need.get(word)) {
                    String left = s.substring(l, l + w);
                    seen.merge(left, -1, Integer::sum);
                    l += w;
                    count--;
                }
                if (count == k) res.add(l);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(findSubstring("barfoothefoobarman", new String[]{"foo", "bar"}));       // [0,9]
        System.out.println(findSubstring("wordgoodgoodgoodbestword", new String[]{"word", "good", "best", "word"})); // []
        System.out.println(findSubstring("barfoofoobarthefoobarman", new String[]{"bar", "foo", "the"})); // [6,9,12]
    }
}
