import java.util.HashMap;
import java.util.Map;

public class maxPointsOnALine {

	// Return the maximum number of points that lie on the same straight line.
	public static int maxPoints(int[][] points) {
		if (points == null || points.length == 0) {
			return 0;
		}
		if (points.length <= 2) {
			return points.length;
		}

		int globalMax = 1;

		for (int i = 0; i < points.length; i++) {
			Map<String, Integer> slopeCount = new HashMap<>();
			int duplicates = 0;
			int localMax = 0;

			for (int j = i + 1; j < points.length; j++) {
				int dx = points[j][0] - points[i][0];
				int dy = points[j][1] - points[i][1];

				if (dx == 0 && dy == 0) {
					duplicates++;
					continue;
				}

				int gcd = gcd(dx, dy);
				dx /= gcd;
				dy /= gcd;

				// Keep one canonical form for each slope.
				if (dx < 0) {
					dx = -dx;
					dy = -dy;
				} else if (dx == 0) {
					dy = 1;
				} else if (dy == 0) {
					dx = 1;
				}

				String key = dy + "/" + dx;
				int count = slopeCount.getOrDefault(key, 0) + 1;
				slopeCount.put(key, count);
				localMax = Math.max(localMax, count);
			}

			globalMax = Math.max(globalMax, localMax + duplicates + 1);
		}

		return globalMax;
	}

	private static int gcd(int a, int b) {
		a = Math.abs(a);
		b = Math.abs(b);

		while (b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}

		return a == 0 ? 1 : a;
	}

	public static void main(String[] args) {
		int[][] points1 = {{1, 1}, {2, 2}, {3, 3}};
		int[][] points2 = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

		System.out.println(maxPoints(points1)); // 3
		System.out.println(maxPoints(points2)); // 4
	}
}
