public class factorialTrailingZeroes2 {

	public static int trailingZeroes(int n) {
		int count = 0;

		while (n > 0) {
			n /= 5;
			count += n;
		}

		return count;
	}

	public static void main(String[] args) {
		System.out.println(trailingZeroes(3));  // 0
		System.out.println(trailingZeroes(5));  // 1
		System.out.println(trailingZeroes(10)); // 2
		System.out.println(trailingZeroes(25)); // 6
		System.out.println(trailingZeroes(100)); // 24
	}
}
