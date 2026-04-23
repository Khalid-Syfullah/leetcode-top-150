import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class findKPairsWithSmallestSums {

	public static List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
		List<List<Integer>> result = new ArrayList<>();

        if (nums1.length == 0 || nums2.length == 0 || k == 0) {
            return result;
        }

        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a[0] + a[1], b[0] + b[1]));

        for (int i = 0; i < Math.min(k, nums1.length); i++) {

            minHeap.offer(new int[]{nums1[i], nums2[0], 0});
        }

        while (k > 0 && !minHeap.isEmpty()){
            int[] curr = minHeap.poll();
            int first = curr[0];
            int second = curr[1];
            int j = curr[2];
            List<Integer> pair = new ArrayList<>();
            pair.add(first);
            pair.add(second);
            result.add(pair);

            if (j + 1 < nums2.length) {
                minHeap.offer(new int[]{first, nums2[j + 1], j + 1});
            }

            k--;
        }
        return result;
	}

	public static void main(String[] args) {
		System.out.println(kSmallestPairs(new int[]{1, 7, 11}, new int[]{2, 4, 6}, 3));
		System.out.println(kSmallestPairs(new int[]{1, 1, 2}, new int[]{1, 2, 3}, 2));
	}
}
