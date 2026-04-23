public class BitwiseANDofNumbersRange {

	public static int rangeBitwiseAnd(int left, int right) {
		int shifts = 0;

		while (left < right) {
			left >>= 1;
			right >>= 1;
			shifts++;
		}

		return left << shifts;
	}

	public static void main(String[] args) {
		System.out.println(rangeBitwiseAnd(5, 7));   // 4
		System.out.println(rangeBitwiseAnd(0, 0));   // 0
		System.out.println(rangeBitwiseAnd(1, 2147483647)); // 0
		System.out.println(rangeBitwiseAnd(12, 15)); // 12
	}
}
