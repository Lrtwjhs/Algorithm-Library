
/**
 * Created by lrtwjhs on 2018/6/22.
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

public class Solution {
	public int removeDuplicates(int[] A) {
	    if (A.length == 0) return 0;
	    int i = 0;
	    for (int j = 0; j < A.length; j++) {
	        if(A[j] != A[i]) {
	        	A[++i] = A[j];
	        }
	    }
	    return ++i;
	}
}