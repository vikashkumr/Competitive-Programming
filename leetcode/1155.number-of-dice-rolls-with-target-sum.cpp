/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
public:
    long long dp[31][1001];
    const int mod = 1e9+7;
    int solve(int d, int f, int target) {
        if(target == 0 and d == 0) return 1;
        
        if(d<=0 or target<0) return 0;
        
        long long &res = dp[d][target];
        if(res != -1) return res;
        
        long long ans = 0;
        for(int i=1;i<=f;i++) {
            ans += solve(d-1, f, target-i);
        }
        return res = ans%mod;
    }
    
    
    int numRollsToTarget(int d, int f, int target) {
        memset(dp, -1, sizeof dp);
        return solve(d, f, target);
    }
};
// @lc code=end

