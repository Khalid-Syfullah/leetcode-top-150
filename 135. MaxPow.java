public class maxPow {

	// Compute x raised to the power n (x^n) using fast exponentiation.
	public static double myPow(double x, int n) {
		long N = n; // use long to handle Integer.MIN_VALUE
		double result = 1.0;
		if (N < 0) {
			x = 1.0 / x;
			N = -N;
		}

		while (N > 0) {
			if ((N & 1) == 1) {
				result *= x; // multiply when the current bit is 1
			}
			x *= x; // square the base
			N >>= 1; // shift right (divide exponent by 2)
		}

		return result;
	}

	public static void main(String[] args) {
		System.out.println(myPow(2.00000, 10)); // 1024.0
		System.out.println(myPow(2.10000, 3));  // ~9.261
		System.out.println(myPow(2.00000, -2)); // 0.25
		System.out.println(myPow(0.00001, 2147483647)); // small number, test large exponent
		System.out.println(myPow(1.00000, -2147483648)); // 1.0 edge case
	}

}
