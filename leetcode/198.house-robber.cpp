/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int dp[101];
    int solve(int pos, vector<int>& v) {
        if(pos >= v.size()) return 0;
        int ans = 0;
        int &res = dp[pos];
        if(res != -1) return res;
        for(int i=pos+2;i<=v.size()+2;i++) {
            ans = max(ans, v[pos] + solve(i, v));
        }
        return res = ans;
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        int x = solve(0, nums);
        int y = solve(1, nums);
        return max(x,y);
    }
};
// @lc code=end

