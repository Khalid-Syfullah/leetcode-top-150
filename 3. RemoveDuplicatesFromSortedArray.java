public class RemoveDuplicatesFromSortedArray {

    public static int removeDuplicates(int[] nums) {
        int k = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }

    public static void main(String[] args) {
        int[] a = {1, 1, 2};
        int ka = removeDuplicates(a);
        System.out.println("Expected: 2, Got: " + ka); // [1,2]

        int[] b = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int kb = removeDuplicates(b);
        System.out.println("Expected: 5, Got: " + kb); // [0,1,2,3,4]
    }
}
