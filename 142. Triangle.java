import java.util.List;
import java.util.ArrayList;

public class triangle {

    public static int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }

       int n = triangle.size();
       int[] dp = new int[n];

       for (int j = 0; j < n; j++) {
           dp[j] = triangle.get(n - 1).get(j);
       }

       for (int i = n - 2; i >= 0; i--) {
           for (int j = 0; j <= i; j++) {
               dp[j] = triangle.get(i).get(j) + Math.min(dp[j], dp[j + 1]);
           }
       }
       return dp[0];
    }

    public static void main(String[] args) {
        // Test case 1: [[2],[3,4],[6,5,7],[4,1,8,3]]
        List<List<Integer>> triangle1 = new ArrayList<>();
        triangle1.add(new ArrayList<>(List.of(2)));
        triangle1.add(new ArrayList<>(List.of(3, 4)));
        triangle1.add(new ArrayList<>(List.of(6, 5, 7)));
        triangle1.add(new ArrayList<>(List.of(4, 1, 8, 3)));
        System.out.println(minimumTotal(triangle1)); // Expected: 11 (2+3+5+1)

        // Test case 2: [[-10]]
        List<List<Integer>> triangle2 = new ArrayList<>();
        triangle2.add(new ArrayList<>(List.of(-10)));
        System.out.println(minimumTotal(triangle2)); // Expected: -10

        // Test case 3: [[1],[2,3]]
        List<List<Integer>> triangle3 = new ArrayList<>();
        triangle3.add(new ArrayList<>(List.of(1)));
        triangle3.add(new ArrayList<>(List.of(2, 3)));
        System.out.println(minimumTotal(triangle3)); // Expected: 3 (1+2)
    }

}
