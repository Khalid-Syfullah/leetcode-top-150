import java.util.Arrays;

public class productOfArrayExceptSelf {

    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(productExceptSelf(new int[] {1, 2, 3, 4})));
        System.out.println(Arrays.toString(productExceptSelf(new int[] {-1, 1, 0, -3, 3})));
    }
}
