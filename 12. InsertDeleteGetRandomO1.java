import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class InsertDeleteGetRandomO1 {

    static class RandomizedSet {
        private final List<Integer> list = new ArrayList<>();
        private final Map<Integer, Integer> idx = new HashMap<>();
        private final Random rng = new Random();

        public boolean insert(int val) {
            if (idx.containsKey(val)) return false;
            idx.put(val, list.size());
            list.add(val);
            return true;
        }

        public boolean remove(int val) {
            Integer i = idx.remove(val);
            if (i == null) return false;
            int last = list.size() - 1;
            if (i != last) {
                int lv = list.get(last);
                list.set(i, lv);
                idx.put(lv, i);
            }
            list.remove(last);
            return true;
        }

        public int getRandom() {
            return list.get(rng.nextInt(list.size()));
        }
    }

    public static void main(String[] args) {
        RandomizedSet s = new RandomizedSet();
        System.out.println(s.insert(1));    // true
        System.out.println(s.remove(2));    // false
        System.out.println(s.insert(2));    // true
        System.out.println(s.getRandom());  // 1 or 2
        System.out.println(s.remove(1));    // true
        System.out.println(s.insert(2));    // false
        System.out.println(s.getRandom());  // 2
    }
}
