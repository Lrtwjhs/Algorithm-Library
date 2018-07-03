
/**
 * Created by lrtwjhs on 2018/6/25.
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/
 */

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode p = l1, q = l2, cur = dummy;

        for ( ; p != null && q != null; ) {
            if (p.val < q.val) {
                cur.next = p;
                p = p.next;
            } else {
                cur.next = q;
                q = q.next;
            }
            cur = cur.next;
        }
        cur.next = p != null ? p : q;
        return dummy.next;
    }
}