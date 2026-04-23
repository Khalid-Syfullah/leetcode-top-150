public class RemoveElement {

    public static int removeElement(int[] nums, int val) {
        int k = 0;
        for (int n : nums) {
            if (n != val) nums[k++] = n;
        }
        return k;
    }

    public static void main(String[] args) {
        System.out.println(removeElement(new int[]{3, 2, 2, 3}, 3));             // 2
        System.out.println(removeElement(new int[]{0, 1, 2, 2, 3, 0, 4, 2}, 2)); // 5
        System.out.println(removeElement(new int[]{}, 1));                       // 0
    }
}
