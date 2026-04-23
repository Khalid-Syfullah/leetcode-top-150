import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class CourseSchedule {

    public static boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        int[] indegree = new int[numCourses];

        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] prerequisite : prerequisites) {
            int course = prerequisite[0];
            int required = prerequisite[1];
            graph.get(required).add(course);
            indegree[course]++;
        }

        Queue<Integer> queue = new ArrayDeque<>();
        for (int course = 0; course < numCourses; course++) {
            if (indegree[course] == 0) {
                queue.offer(course);
            }
        }

        int completed = 0;
        while (!queue.isEmpty()) {
            int current = queue.poll();
            completed++;

            for (int next : graph.get(current)) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }

        return completed == numCourses;
    }

    public static void main(String[] args) {
        System.out.println(canFinish(2, new int[][]{{1, 0}}));
        System.out.println(canFinish(2, new int[][]{{1, 0}, {0, 1}}));
        System.out.println(canFinish(4, new int[][]{{1, 0}, {2, 0}, {3, 1}, {3, 2}}));
    }
}
