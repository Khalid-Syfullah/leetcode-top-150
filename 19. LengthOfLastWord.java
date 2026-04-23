public class LengthOfLastWord {

    public static int lengthOfLastWord(String s) {
        int i = s.length() - 1, len = 0;
        while (i >= 0 && s.charAt(i) == ' ') i--;
        while (i >= 0 && s.charAt(i) != ' ') { len++; i--; }
        return len;
    }

    public static void main(String[] args) {
        System.out.println(lengthOfLastWord("Hello World"));              // 5
        System.out.println(lengthOfLastWord("   fly me   to   the moon ")); // 4
        System.out.println(lengthOfLastWord("luffy is still joyboy"));    // 6
    }
}
