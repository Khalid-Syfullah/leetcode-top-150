public class reverseBits {

	public static int reverseBits(int n) {
		int result = 0;

		for (int i = 0; i < 32; i++) {
			result <<= 1;
			result |= (n & 1);
			n >>>= 1;
		}

		return result;
	}

	public static void main(String[] args) {
		System.out.println(reverseBits(43261596));   // 964176192
		System.out.println(reverseBits(-3));         // example with negative input
	}
}
