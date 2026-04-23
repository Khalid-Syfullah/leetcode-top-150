public class BestTimeToBuyAndSellStock {

    public static int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE, best = 0;
        for (int p : prices) {
            if (p < min) min = p;
            else if (p - min > best) best = p - min;
        }
        return best;
    }

    public static void main(String[] args) {
        System.out.println(maxProfit(new int[]{7, 1, 5, 3, 6, 4})); // 5
        System.out.println(maxProfit(new int[]{7, 6, 4, 3, 1}));    // 0
        System.out.println(maxProfit(new int[]{2, 4, 1}));          // 2
    }
}
