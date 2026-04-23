import java.util.PriorityQueue;

public class findMedianFromDataStream {

	private PriorityQueue<Integer> small;
	private PriorityQueue<Integer> large;

	public findMedianFromDataStream() {
		small = new PriorityQueue<>((a, b) -> b - a);
		large = new PriorityQueue<>();
	}

	public void addNum(int num) {
		small.offer(num);
		large.offer(small.poll());

		if (large.size() > small.size()) {
			small.offer(large.poll());
		}
	}

	public double findMedian() {
		if (small.size() > large.size()) {
			return small.peek();
		}

		return (small.peek() + large.peek()) / 2.0;
	}

	public static void main(String[] args) {
		findMedianFromDataStream medianFinder = new findMedianFromDataStream();
		medianFinder.addNum(1);
		medianFinder.addNum(2);
		System.out.println(medianFinder.findMedian()); // 1.5
		medianFinder.addNum(3);
		System.out.println(medianFinder.findMedian()); // 2.0
	}
}
