public class removeDuplicatesFromSortedListII {

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

    public static ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;

        while (head != null) {
            if (head.next != null && head.val == head.next.val) {
                int duplicateVal = head.val;
                while (head != null && head.val == duplicateVal) {
                    head = head.next;
                }
                prev.next = head;
            } else {
                prev = prev.next;
                head = head.next;
            }
        }

        return dummy.next;
    }

    private static ListNode build(int... values) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for (int value : values) {
            tail.next = new ListNode(value);
            tail = tail.next;
        }
        return dummy.next;
    }

    private static void print(ListNode head) {
        ListNode curr = head;
        while (curr != null) {
            System.out.print(curr.val);
            if (curr.next != null) {
                System.out.print(" -> ");
            }
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode a = build(1, 2, 3, 3, 4, 4, 5);
        ListNode b = build(1, 1, 1, 2, 3);
        ListNode c = build(1, 1);

        print(deleteDuplicates(a));
        print(deleteDuplicates(b));
        print(deleteDuplicates(c));
    }
}
