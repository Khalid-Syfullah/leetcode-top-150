import java.util.ArrayDeque;
import java.util.Deque;

public class MinStack {

    static class Stack {
        private final Deque<int[]> s = new ArrayDeque<>();

        public void push(int val) {
            int min = s.isEmpty() ? val : Math.min(val, s.peek()[1]);
            s.push(new int[]{val, min});
        }

        public void pop() { s.pop(); }
        public int top() { return s.peek()[0]; }
        public int getMin() { return s.peek()[1]; }
    }

    public static void main(String[] args) {
        Stack ms = new Stack();
        ms.push(-2);
        ms.push(0);
        ms.push(-3);
        System.out.println(ms.getMin()); // -3
        ms.pop();
        System.out.println(ms.top());    // 0
        System.out.println(ms.getMin()); // -2
    }
}
