
/**
 * Created by lrtwjhs on 2018/6/27.
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 */

class Solution {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE, prev = 0;
        for (int i = 0; i < nums.length; i++) {
            prev = Math.max(nums[i], nums[i] + prev);
            max = Math.max(max, prev);
        }
        return max;
    }
}