/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    int dp[20001][201];
    bool solve(vector<int>&nums, int curr_sum, int tot_sum, int pos) {
        if(pos == nums.size()) 
            return curr_sum == (tot_sum - curr_sum);

        int &ans = dp[curr_sum][pos];
        if(ans != -1) return ans;

        bool op1 = solve(nums, curr_sum + nums[pos], tot_sum, pos + 1);
        bool op2 = solve(nums, curr_sum, tot_sum, pos + 1);
        return ans = (op1 || op2);
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        memset(dp, -1, sizeof dp);
        return solve(nums, 0, totalSum, 0);
    }
};
// @lc code=end

