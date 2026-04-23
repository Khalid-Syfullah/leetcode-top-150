import java.util.Arrays;
import java.util.PriorityQueue;

public class ipo {

	public static int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
		int n = profits.length;
		int[][] projects = new int[n][2];

		for (int i = 0; i < n; i++) {
			projects[i][0] = capital[i];
			projects[i][1] = profits[i];
		}

		Arrays.sort(projects, (a, b) -> Integer.compare(a[0], b[0]));

		PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
		int currentCapital = w;
		int index = 0;

		for (int i = 0; i < k; i++) {
			while (index < n && projects[index][0] <= currentCapital) {
				maxHeap.offer(projects[index][1]);
				index++;
			}

			if (maxHeap.isEmpty()) {
				break;
			}

			currentCapital += maxHeap.poll();
		}

		return currentCapital;
	}

	public static void main(String[] args) {
		System.out.println(findMaximizedCapital(2, 0, new int[]{1, 2, 3}, new int[]{0, 1, 1})); // 4
		System.out.println(findMaximizedCapital(3, 0, new int[]{1, 2, 3}, new int[]{0, 1, 2})); // 6
	}
}
