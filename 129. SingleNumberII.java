public class singleNumberII {

	public static int singleNumber(int[] nums) {
		int ones = 0;
		int twos = 0;

		for (int num : nums) {
			ones = (ones ^ num) & ~twos;
			twos = (twos ^ num) & ~ones;
		}

		return ones;
	}

	public static void main(String[] args) {
		System.out.println(singleNumber(new int[]{2, 2, 3, 2})); // 3
		System.out.println(singleNumber(new int[]{0, 1, 0, 1, 0, 1, 99})); // 99
		System.out.println(singleNumber(new int[]{-2, -2, -2, -7})); // -7
	}
}
