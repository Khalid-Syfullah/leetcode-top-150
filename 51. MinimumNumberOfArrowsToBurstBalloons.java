import java.util.Arrays;

public class minimumNumberOfArrowsToBurstBalloons {

    public static int findMinArrowShots(int[][] points) {
        if (points.length == 0) {
            return 0;
        }

        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

        int arrows = 1;
        int arrowPos = points[0][1];

        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1];
            }
        }

        return arrows;
    }

    public static void main(String[] args) {
        int[][] points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
        int[][] points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
        int[][] points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

        System.out.println(findMinArrowShots(points1));
        System.out.println(findMinArrowShots(points2));
        System.out.println(findMinArrowShots(points3));
    }
}
