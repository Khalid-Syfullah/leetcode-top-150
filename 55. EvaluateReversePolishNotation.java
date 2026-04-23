import java.util.ArrayDeque;
import java.util.Deque;

public class EvaluateReversePolishNotation {

    public static int evalRPN(String[] tokens) {
        Deque<Integer> s = new ArrayDeque<>();
        for (String t : tokens) {
            switch (t) {
                case "+": case "-": case "*": case "/":
                    int b = s.pop(), a = s.pop();
                    if (t.equals("+")) s.push(a + b);
                    else if (t.equals("-")) s.push(a - b);
                    else if (t.equals("*")) s.push(a * b);
                    else s.push(a / b);
                    break;
                default:
                    s.push(Integer.parseInt(t));
            }
        }
        return s.pop();
    }

    public static void main(String[] args) {
        System.out.println(evalRPN(new String[]{"2", "1", "+", "3", "*"})); // 9
        System.out.println(evalRPN(new String[]{"4", "13", "5", "/", "+"})); // 6
        System.out.println(evalRPN(new String[]{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"})); // 22
    }
}
