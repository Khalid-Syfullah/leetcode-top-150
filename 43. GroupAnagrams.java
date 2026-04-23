import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class groupAnagrams {

    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> groups = new HashMap<>();

        for (String str : strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);

            groups.computeIfAbsent(key, k -> new ArrayList<>()).add(str);
        }

        return new ArrayList<>(groups.values());
    }

    public static void main(String[] args) {
        String[] words1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
        String[] words2 = {""};
        String[] words3 = {"a"};

        System.out.println(groupAnagrams(words1));
        System.out.println(groupAnagrams(words2));
        System.out.println(groupAnagrams(words3));
    }
}
