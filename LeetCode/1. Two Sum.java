
/**
 * Created by lrtwjhs on 2018/6/22.
 *
 * https://leetcode.com/problems/two-sum/
 */

public class Solution {
    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {

            Integer v = map.get(target - nums[i]);

            if (v != null && v != i) {
                return new int[]{i, v};
            }
        }
        return null;
    }
}