
/**
 * Created by lrtwjhs on 2018/6/24.
 *
 * https://leetcode.com/problems/palindrome-number/
 */

class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int y = 1;
        for ( ; y <= x / 10; y *= 10);

        for (int t = 1; t < y; t *= 10, y /= 10) {
            if ((x / y) % 10 != (x / t) % 10) {
                    return false;
            }
        }
        return true;
    }
}