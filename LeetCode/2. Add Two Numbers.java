
/**
 * Created by lrtwjhs on 2018/6/22.
 */

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode r = new ListNode(0);
        ListNode h = r;
        ListNode beforeend = r;

        while (l1 != null && l2 != null) {
        	r.val += l1.val + l2.val;

        	r.next = new ListNode(r.val / 10);
        	r.val %= 10;

        	beforeend = r;
        	r = r.next;
        	l1 = l1.next;
        	l2 = l2.next;
        }

        ListNode rest;
        if (l1 == null) rest = l2; else rest = l1;

        while (rest != null) {
        	r.val += rest.val;

        	r.next = new ListNode(r.val / 10);
        	r.val %= 10;

        	beforeend = r;
        	r = r.next;
        	rest = rest.next;
        }

        if (beforeend.next != null && beforeend.next.val == 0) beforeend.next = null;

        return h;
    }
}