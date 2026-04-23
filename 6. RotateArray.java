import java.util.Arrays;

public class RotateArray {

    // Reverse approach: O(n) time, O(1) space
    // 1. Reverse entire array
    // 2. Reverse first k elements
    // 3. Reverse remaining n-k elements
    static void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    static void reverse(int[] nums, int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left++] = nums[right];
            nums[right--] = tmp;
        }
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 4, 5, 6, 7};
        rotate(nums1, 3);
        System.out.println("Expected: [5, 6, 7, 1, 2, 3, 4]");
        System.out.println("Actual:   " + Arrays.toString(nums1));

        int[] nums2 = {-1, -100, 3, 99};
        rotate(nums2, 2);
        System.out.println("Expected: [3, 99, -1, -100]");
        System.out.println("Actual:   " + Arrays.toString(nums2));

        int[] nums3 = {1, 2};
        rotate(nums3, 5);
        System.out.println("Expected: [2, 1]");
        System.out.println("Actual:   " + Arrays.toString(nums3));
    }
}
