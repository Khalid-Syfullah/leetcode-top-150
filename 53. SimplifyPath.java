import java.util.ArrayDeque;
import java.util.Deque;

public class SimplifyPath {

    public static String simplifyPath(String path) {
        Deque<String> stack = new ArrayDeque<>();
        for (String part : path.split("/")) {
            if (part.isEmpty() || part.equals(".")) continue;
            if (part.equals("..")) { if (!stack.isEmpty()) stack.pop(); }
            else stack.push(part);
        }
        StringBuilder sb = new StringBuilder();
        for (String p : (Iterable<String>) stack::descendingIterator) sb.append('/').append(p);
        return sb.length() == 0 ? "/" : sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(simplifyPath("/home/"));         // /home
        System.out.println(simplifyPath("/../"));           // /
        System.out.println(simplifyPath("/home//foo/"));    // /home/foo
        System.out.println(simplifyPath("/a/./b/../../c/"));// /c
    }
}
