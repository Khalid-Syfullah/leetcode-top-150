import java.util.Arrays;

public class TwoSumII {

    public static int[] twoSum(int[] numbers, int target) {
        int l = 0, r = numbers.length - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return new int[]{l + 1, r + 1};
            if (sum < target) l++; else r--;
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(twoSum(new int[]{2, 7, 11, 15}, 9))); // [1,2]
        System.out.println(Arrays.toString(twoSum(new int[]{2, 3, 4}, 6)));      // [1,3]
        System.out.println(Arrays.toString(twoSum(new int[]{-1, 0}, -1)));       // [1,2]
    }
}
