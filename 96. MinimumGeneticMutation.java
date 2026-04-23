import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

public class MinimumGeneticMutation {

    public static int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> bankSet = new HashSet<>();
        for (String gene : bank) {
            bankSet.add(gene);
        }

        if (!bankSet.contains(endGene)) {
            return -1;
        }

        char[] choices = {'A', 'C', 'G', 'T'};
        Queue<String> queue = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();

        queue.offer(startGene);
        visited.add(startGene);

        int mutations = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                String current = queue.poll();

                if (current.equals(endGene)) {
                    return mutations;
                }

                char[] chars = current.toCharArray();

                for (int j = 0; j < chars.length; j++) {
                    char original = chars[j];

                    for (char choice : choices) {
                        if (choice == original) {
                            continue;
                        }

                        chars[j] = choice;
                        String next = new String(chars);

                        if (bankSet.contains(next) && !visited.contains(next)) {
                            visited.add(next);
                            queue.offer(next);
                        }
                    }

                    chars[j] = original;
                }
            }

            mutations++;
        }

        return -1;
    }

    public static void main(String[] args) {
        System.out.println(minMutation("AACCGGTT", "AACCGGTA", new String[]{"AACCGGTA"}));
        System.out.println(minMutation("AACCGGTT", "AAACGGTA", new String[]{"AACCGGTA", "AACCGCTA", "AAACGGTA"}));
        System.out.println(minMutation("AAAAACCC", "AACCCCCC", new String[]{"AAAACCCC", "AAACCCCC", "AACCCCCC"}));
        System.out.println(minMutation("AACCGGTT", "AACCGGTA", new String[]{}));
    }
}
