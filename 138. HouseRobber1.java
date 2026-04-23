class houseRobber1 {
    public int rob(int[] nums) {
        int n = nums.length;
        
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < n; i++) {
            int curr = Math.max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    public static void main(String[] args) {
        houseRobber1 solver = new houseRobber1();

        System.out.println(solver.rob(new int[] {1,2,3,1})); // expected 4
        System.out.println(solver.rob(new int[] {2,7,9,3,1})); // expected 12
        System.out.println(solver.rob(new int[] {2})); // expected 2
        System.out.println(solver.rob(new int[] {})); // expected 0
        System.out.println(solver.rob(new int[] {6,6,4,8,4,3,3,10})); // expected 27
    }
}