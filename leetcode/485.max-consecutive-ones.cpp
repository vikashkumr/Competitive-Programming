/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]) {
                int cnt = 0;
                while(i<nums.size() and nums[i]) {
                    cnt++;
                    i++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
// @lc code=end

