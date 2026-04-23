public class designAddAndSearchDataStructure {

    static class WordDictionary {
        private final TrieNode root;

        public WordDictionary() {
            this.root = new TrieNode();
        }

        public void addWord(String word) {
            TrieNode node = root;
            for (char ch : word.toCharArray()) {
                int index = ch - 'a';
                if (node.children[index] == null) {
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
            }
            node.isEndOfWord = true;
        }

        public boolean search(String word) {
            return dfs(word, 0, root);
        }

        private boolean dfs(String word, int pos, TrieNode node) {
            if (node == null) {
                return false;
            }

            if (pos == word.length()) {
                return node.isEndOfWord;
            }

            char ch = word.charAt(pos);
            if (ch == '.') {
                for (TrieNode child : node.children) {
                    if (child != null && dfs(word, pos + 1, child)) {
                        return true;
                    }
                }
                return false;
            }

            return dfs(word, pos + 1, node.children[ch - 'a']);
        }
    }

    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEndOfWord;
    }

    public static void main(String[] args) {
        WordDictionary wordDictionary = new WordDictionary();
        wordDictionary.addWord("bad");
        wordDictionary.addWord("dad");
        wordDictionary.addWord("mad");

        System.out.println(wordDictionary.search("pad"));
        System.out.println(wordDictionary.search("bad"));
        System.out.println(wordDictionary.search(".ad"));
        System.out.println(wordDictionary.search("b.."));
    }
}
