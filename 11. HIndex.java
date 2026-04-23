import java.util.Arrays;

public class HIndex {

    public static int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n = citations.length;
        for (int i = 0; i < n; i++) {
            int h = n - i;
            if (citations[i] >= h) return h;
        }
        return 0;
    }

    public static void main(String[] args) {
        System.out.println(hIndex(new int[]{3, 0, 6, 1, 5})); // 3
        System.out.println(hIndex(new int[]{1, 3, 1}));       // 1
        System.out.println(hIndex(new int[]{0}));             // 0
    }
}
