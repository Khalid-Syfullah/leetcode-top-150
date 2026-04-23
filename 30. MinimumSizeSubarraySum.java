public class MinimumSizeSubarraySum {

    public static int minSubArrayLen(int target, int[] nums) {
        int l = 0, sum = 0, best = Integer.MAX_VALUE;
        for (int r = 0; r < nums.length; r++) {
            sum += nums[r];
            while (sum >= target) {
                best = Math.min(best, r - l + 1);
                sum -= nums[l++];
            }
        }
        return best == Integer.MAX_VALUE ? 0 : best;
    }

    public static void main(String[] args) {
        System.out.println(minSubArrayLen(7, new int[]{2, 3, 1, 2, 4, 3}));    // 2
        System.out.println(minSubArrayLen(4, new int[]{1, 4, 4}));             // 1
        System.out.println(minSubArrayLen(11, new int[]{1, 1, 1, 1, 1, 1, 1})); // 0
    }
}
