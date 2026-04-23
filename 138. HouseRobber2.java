// LeetCode #213
class houseRobber2 {
    public int rob(int[] nums) {
        int n = nums.length;

        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = nums[0];
        int prev1 = Math.max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int curr = Math.max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    public static void main(String[] args) {
        houseRobber2 solver = new houseRobber2();

        System.out.println(solver.rob(new int[] {1,2,3,1})); // expected 4
        System.out.println(solver.rob(new int[] {2,7,9,3,1})); // expected 12
        System.out.println(solver.rob(new int[] {2})); // expected 2
        System.out.println(solver.rob(new int[] {})); // expected 0
        System.out.println(solver.rob(new int[] {6,6,4,8,4,3,3,10})); // expected 27
    }
}