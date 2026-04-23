class houseRobber3 {
    public int rob(int[] nums) {
        int n = nums.length;

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int[] dp = new int[n];

        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);

        for (int i = 2; i < n; i++){
            dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }

    public static void main(String[] args) {
        houseRobber3 solver = new houseRobber3();

        System.out.println(solver.rob(new int[] {1,2,3,1})); // expected 4
        System.out.println(solver.rob(new int[] {2,7,9,3,1})); // expected 12
        System.out.println(solver.rob(new int[] {2})); // expected 2
        System.out.println(solver.rob(new int[] {})); // expected 0
        System.out.println(solver.rob(new int[] {6,6,4,8,4,3,3,10})); // expected 27
    }
}