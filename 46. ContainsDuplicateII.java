import java.util.HashMap;
import java.util.Map;

public class ContainsDuplicateII {

    public static boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> last = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            Integer j = last.get(nums[i]);
            if (j != null && i - j <= k) return true;
            last.put(nums[i], i);
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(containsNearbyDuplicate(new int[]{1, 2, 3, 1}, 3));       // true
        System.out.println(containsNearbyDuplicate(new int[]{1, 0, 1, 1}, 1));       // true
        System.out.println(containsNearbyDuplicate(new int[]{1, 2, 3, 1, 2, 3}, 2)); // false
    }
}
