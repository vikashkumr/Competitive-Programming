/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    vector<int>dp;
    int ways(int total, vector<int>& nums, int target) {
        if(total > target) return 0;
        if(total == target) return 1;
        int &res = dp[total];
        if(res != -1) return res;
        int ans = 0;
        for(int i=0;i<nums.size(); i++) {
            if(total + nums[i] <= target) {
               ans += ways(total + nums[i], nums, target);
            }
        }
        return res = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1, -1);
        return ways(0, nums, target);            
    }
};
// @lc code=end

