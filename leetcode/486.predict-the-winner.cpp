/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:

    int dp[21][21];
    int solve(int i, int j, vector<int>& nums) {
        if(i>j) return 0;

        int &ans = dp[i][j];
        if(ans != -1) return ans;

        int op1 = nums[i] - solve(i+1, j, nums);
        int op2 = nums[j] - solve(i, j-1, nums);
        return ans = max(op1,op2);
    }


    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        //if player 1 score1 is greater difference of score will be positive return true
        return solve(0, nums.size()-1,nums) >= 0;
    }
};
// @lc code=end

