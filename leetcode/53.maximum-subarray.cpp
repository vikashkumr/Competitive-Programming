/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
/*
Aproach: 
1. keep two variable final_max and max_so_far 
2. update final_max when arr[i] is negative // important point
3. notice here we have to print atleast 1 element
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int final_max = nums[0];
        int max_so_far = nums[0];
        for (int i = 1; i < nums.size();i++) {
            if(nums[i] < 0) {
                final_max = max(final_max, max_so_far);
                max_so_far = max(max_so_far+nums[i], nums[i]);
            } else {
                max_so_far = max(max_so_far+nums[i], nums[i]);
            }
        }
        return max(final_max, max_so_far);
    }
};
// @lc code=end

