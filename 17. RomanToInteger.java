public class RomanToInteger {

    public static int romanToInt(String s) {
        int total = 0, prev = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int v = value(s.charAt(i));
            total += v < prev ? -v : v;
            prev = v;
        }
        return total;
    }

    private static int value(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    public static void main(String[] args) {
        System.out.println(romanToInt("III"));     // 3
        System.out.println(romanToInt("LVIII"));   // 58
        System.out.println(romanToInt("MCMXCIV")); // 1994
    }
}
