public class rotateList {

    static class ListNode {
        int val;
        ListNode next;

        ListNode() {}

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public static ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        int length = 1;
        ListNode tail = head;
        while (tail.next != null) {
            tail = tail.next;
            length++;
        }

        k %= length;
        if (k == 0) {
            return head;
        }

        tail.next = head;

        int stepsToNewTail = length - k - 1;
        ListNode newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail.next;
        }

        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }

    private static ListNode build(int... values) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        for (int value : values) {
            cur.next = new ListNode(value);
            cur = cur.next;
        }
        return dummy.next;
    }

    private static void print(ListNode head) {
        ListNode cur = head;
        while (cur != null) {
            System.out.print(cur.val);
            if (cur.next != null) {
                System.out.print(" -> ");
            }
            cur = cur.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode a = build(1, 2, 3, 4, 5);
        print(rotateRight(a, 2));

        ListNode b = build(0, 1, 2);
        print(rotateRight(b, 4));
    }
}
