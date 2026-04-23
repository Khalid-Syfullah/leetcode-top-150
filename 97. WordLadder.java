import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

public class WordLadder {

    public static int ladderLength(String beginWord, String endWord, java.util.List<String> wordList) {
        Set<String> words = new HashSet<>(wordList);
        if (!words.contains(endWord)) {
            return 0;
        }

        Queue<String> queue = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();

        queue.offer(beginWord);
        visited.add(beginWord);

        int length = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                String current = queue.poll();
                if (current.equals(endWord)) {
                    return length;
                }

                char[] chars = current.toCharArray();
                for (int j = 0; j < chars.length; j++) {
                    char original = chars[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) {
                            continue;
                        }

                        chars[j] = ch;
                        String next = new String(chars);

                        if (words.contains(next) && !visited.contains(next)) {
                            visited.add(next);
                            queue.offer(next);
                        }
                    }

                    chars[j] = original;
                }
            }

            length++;
        }

        return 0;
    }

    public static void main(String[] args) {
        System.out.println(ladderLength("hit", "cog", java.util.List.of("hot", "dot", "dog", "lot", "log", "cog")));
        System.out.println(ladderLength("hit", "cog", java.util.List.of("hot", "dot", "dog", "lot", "log")));
        System.out.println(ladderLength("a", "c", java.util.List.of("a", "b", "c")));
    }
}
