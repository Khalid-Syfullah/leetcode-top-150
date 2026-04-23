public class implementTriePrefixTree {

    static class Trie {
        private final TrieNode root;

        Trie() {
            this.root = new TrieNode();
        }

        public void insert(String word) {
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
            TrieNode node = traverse(word);
            return node != null && node.isEndOfWord;
        }

        public boolean startsWith(String prefix) {
            return traverse(prefix) != null;
        }

        private TrieNode traverse(String text) {
            TrieNode node = root;
            for (char ch : text.toCharArray()) {
                int index = ch - 'a';
                if (node.children[index] == null) {
                    return null;
                }
                node = node.children[index];
            }
            return node;
        }
    }

    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEndOfWord;
    }

    public static void main(String[] args) {
        Trie trie = new Trie();

        trie.insert("apple");
        System.out.println(trie.search("apple"));
        System.out.println(trie.search("app"));
        System.out.println(trie.startsWith("app"));
        trie.insert("app");
        System.out.println(trie.search("app"));
    }
}
