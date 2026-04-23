public class linkedListCycle {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    public static boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        ListNode a = new ListNode(3);
        ListNode b = new ListNode(2);
        ListNode c = new ListNode(0);
        ListNode d = new ListNode(-4);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = b;

        ListNode x = new ListNode(1);
        ListNode y = new ListNode(2);
        x.next = y;

        System.out.println(hasCycle(a));
        System.out.println(hasCycle(x));
    }
}
