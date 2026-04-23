import java.util.Arrays;

public class findFirstAndLastPosition {

    public static int[] searchRange(int[] nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) {
            return new int[] {-1, -1};
        }

        int last = findBound(nums, target, false);
        return new int[] {first, last};
    }

    private static int findBound(int[] nums, int target, boolean isFirst) {
        int left = 0;
        int right = nums.length - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                answer = mid;
                if (isFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(searchRange(new int[] {5, 7, 7, 8, 8, 10}, 8)));
        System.out.println(Arrays.toString(searchRange(new int[] {5, 7, 7, 8, 8, 10}, 6)));
        System.out.println(Arrays.toString(searchRange(new int[] {}, 0)));
    }
}
