public class RemoveDuplicatesFromSortedArrayII {

    public static int removeDuplicates(int[] nums) {
        int k = 0;
        for (int n : nums) {
            if (k < 2 || n != nums[k - 2]) nums[k++] = n;
        }
        return k;
    }

    public static void main(String[] args) {
        System.out.println(removeDuplicates(new int[]{1, 1, 1, 2, 2, 3}));          // 5
        System.out.println(removeDuplicates(new int[]{0, 0, 1, 1, 1, 1, 2, 3, 3})); // 7
        System.out.println(removeDuplicates(new int[]{1}));                         // 1
    }
}
