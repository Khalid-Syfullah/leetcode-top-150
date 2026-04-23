public class factorialTrailingZeroes {

	public static int trailingZeroes(int n) {
		int count = 0;
		int divisor = 5;

		while (divisor <= n){
			count += n / divisor;
			divisor *= 5;
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
