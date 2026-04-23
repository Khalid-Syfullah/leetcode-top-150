public class JumpGameII {

    public static int jump(int[] nums) {
        int jumps = 0, end = 0, far = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            far = Math.max(far, i + nums[i]);
            if (i == end) {
                jumps++;
                end = far;
            }
        }
        return jumps;
    }

    public static void main(String[] args) {
        System.out.println(jump(new int[]{2, 3, 1, 1, 4})); // 2
        System.out.println(jump(new int[]{2, 3, 0, 1, 4})); // 2
        System.out.println(jump(new int[]{1}));             // 0
    }
}
