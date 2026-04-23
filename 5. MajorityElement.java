public class MajorityElement {

    // Boyer-Moore Voting Algorithm: O(n) time, O(1) space
    public static int majorityElement(int[] nums) {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }

    public static void main(String[] args) {
        System.out.println(majorityElement(new int[]{3, 2, 3}));           // expected: 3
        System.out.println(majorityElement(new int[]{2, 2, 1, 1, 1, 2, 2})); // expected: 2
        System.out.println(majorityElement(new int[]{1}));                 // expected: 1
    }
}
