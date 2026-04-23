public class IntegerToRoman {

    private static final int[] VALS = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    private static final String[] SYMS = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    public static String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < VALS.length; i++) {
            while (num >= VALS[i]) {
                sb.append(SYMS[i]);
                num -= VALS[i];
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(intToRoman(3));    // III
        System.out.println(intToRoman(58));   // LVIII
        System.out.println(intToRoman(1994)); // MCMXCIV
    }
}
