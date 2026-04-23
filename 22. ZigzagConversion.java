public class ZigzagConversion {

    public static String convert(String s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) rows[i] = new StringBuilder();
        int cur = 0, dir = -1;
        for (char c : s.toCharArray()) {
            rows[cur].append(c);
            if (cur == 0 || cur == numRows - 1) dir = -dir;
            cur += dir;
        }
        StringBuilder out = new StringBuilder();
        for (StringBuilder r : rows) out.append(r);
        return out.toString();
    }

    public static void main(String[] args) {
        System.out.println(convert("PAYPALISHIRING", 3)); // PAHNAPLSIIGYIR
        System.out.println(convert("PAYPALISHIRING", 4)); // PINALSIGYAHRPI
        System.out.println(convert("A", 1));              // A
    }
}
