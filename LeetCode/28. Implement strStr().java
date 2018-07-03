
/**
 * Created by lrtwjhs on 2018/6/25.
 *
 * https://leetcode.com/problems/implement-strstr/
 */

class Solution {
    public int strStr(String haystack, String needle) {
        int l1 = haystack.length(), l2 = needle.length();
        for (int i = 0, j; i + l2 - 1 < l1; i++) {
            for (j = 0; j < l2; j++) {
                if (haystack.charAt(i + j) != needle.charAt(j)) {
                    break;
                }
            }
            if (j >= l2) {
                return i;
            }
        }
        return -1;
    }
}