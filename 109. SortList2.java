import java.util.ArrayList;
import java.util.Collections;

public class sortList2 {

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
    public static ListNode sortListNode(ListNode head) {
        
        ArrayList<Integer> vals = new ArrayList<>();
        ListNode curr = head;
        while (curr != null) {
            vals.add(curr.val);
            curr = curr.next;
        }

        Collections.sort(vals);

        curr = head;
        for (int i = 0; i < vals.size(); i++) {
            curr.val = vals.get(i);
            curr = curr.next;
        }

        return head;
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
        ListNode head1 = build(4, 2, 1, 3);
        ListNode head2 = build(-1, 5, 3, 4, 0);

        print(sortListNode(head1));
        print(sortListNode(head2));
    }
}
