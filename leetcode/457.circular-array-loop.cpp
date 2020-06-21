/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                int slow = i;
                int fast = nums[(i+nums[i])%n];
                while(slow != fast and (nums[slow] > 0 and nums[fast] > 0)) {
                    slow = (slow + nums[slow])%n;
                    fast = (fast + nums[fast] + nums[nums[fast]%n])%n;
                }
                if(slow == fast) return true;
            } else {
                int slow = i;
                int fast = nums[(i - nums[i]+n)%n];
                while(slow != fast and (nums[slow] < 0 and nums[fast] < 0)) {
                    slow = (slow - nums[slow]+n)%n;
                    fast = (fast - nums[fast] - nums[nums[fast]%n] + n)%n;
                }
                if(slow == fast) return true;

            }
        }
        return false;
    }
};
// @lc code=end

