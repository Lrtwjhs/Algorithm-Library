
/**
 * Created by lrtwjhs on 2018/6/24.
 *
 * https://leetcode.com/problems/reverse-integer/
 */

class Solution {
    public int reverse(int x) {
        long y = x, r = 0;
        int sign = x > 0 ? 1: -1; // 判断正负
        y = y > 0 ? y : -y; // 全化为正整数

        for ( ; y > 0; y /= 10) {
            r = r * 10 + y % 10; // 除十取余
        }
        r *= sign;
        if (r > Integer.MAX_VALUE || r < Integer.MIN_VALUE) {
            return 0;
        }
        return (int) r;
    }
}