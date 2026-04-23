public class mySqrt2 {

	// Return the integer square root of x.
	// The decimal part is truncated.
	public static int mySqrt(int x) {
		if (x < 2) {
			return x;
		}

		int left = 1, right = x / 2, ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long square = (long) mid * mid;

            if (square < x) {
                ans = mid;
                left = mid + 1;
            }

            else if (square > x){
                right = mid - 1;
            }

            else {
                return mid;
            }

        }
        return ans;

	}

	public static void main(String[] args) {
		System.out.println(mySqrt(4)); // 2
		System.out.println(mySqrt(8)); // 2
		System.out.println(mySqrt(0)); // 0
		System.out.println(mySqrt(1)); // 1
		System.out.println(mySqrt(2147395599)); // 46339
	}
}
