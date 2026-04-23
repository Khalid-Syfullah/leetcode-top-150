import java.util.Arrays;

public class Candy {

    public static int candy(int[] ratings) {
        int n = ratings.length;
        int[] c = new int[n];
        Arrays.fill(c, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) c[i] = c[i - 1] + 1;
        }
        int total = c[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) c[i] = Math.max(c[i], c[i + 1] + 1);
            total += c[i];
        }
        return total;
    }

    public static void main(String[] args) {
        System.out.println(candy(new int[]{1, 0, 2}));    // 5
        System.out.println(candy(new int[]{1, 2, 2}));    // 4
        System.out.println(candy(new int[]{1, 3, 4, 5, 2})); // 11
    }
}
