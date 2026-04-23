import java.util.HashMap;

public class maxPointsOnALine2 {
    public int maxPoints(int[][] points) {

        if (points == null || points.length == 1) return 0;

        if(points.length == 2) return 2;

        int n = points.length;

        int globalMax = 1;

        for (int i = 0; i < n; i++) {

            HashMap<String, Integer> slopeMap = new HashMap<>();
            int duplicates = 0;
            int localMax = 0;

            for (int j = i + 1; j < n; j++) {

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                int gcd = gcd(dx, dy);

                dx /= gcd;
                dy /= gcd;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                String key = dy + "/" + dx;
                int count = slopeMap.getOrDefault(key, 0) + 1;
                slopeMap.put(key, count);
                localMax = Math.max(localMax, count);
            }
            globalMax = Math.max(globalMax, localMax + duplicates + 1);
        }
        return globalMax;
        
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd (b, a % b);
    }
}
