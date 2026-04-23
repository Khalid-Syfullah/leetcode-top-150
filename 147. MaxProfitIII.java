class maxProfitIII {
    public int maxProfit(int[] prices) {
        int buy1  = Integer.MIN_VALUE;
        int sell1 = 0;
        int buy2  = Integer.MIN_VALUE;
        int sell2 = 0;

        for (int p : prices) {
            buy1  = Math.max(buy1,  -p);          // min cost for 1st buy
            sell1 = Math.max(sell1, buy1 + p);     // max profit after 1st sell
            buy2  = Math.max(buy2,  sell1 - p);    // min effective cost for 2nd buy
            sell2 = Math.max(sell2, buy2 + p);     // max profit after 2nd sell
        }

        return sell2;
    }
}