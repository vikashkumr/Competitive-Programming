/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();
        if(n==0) return 0;
        sort(envelopes.begin(), envelopes.end());
        int *dp = new int[n];
        for(int i=0;i<n;i++) dp[i] = 1;
        int ans = 1;
        for(int i=1;i<n;i++) {
            int wc = envelopes[i][0], hc =  envelopes[i][1];
            for(int j = i-1;j>=0;j--) {
                int wp = envelopes[j][0], hp =  envelopes[j][1];
                if(wp<wc and hp<hc) {
                    dp[i] = max(dp[i],1 + dp[j]);
                    ans = max(ans, dp[i]); 
                }
            }
        }
        return ans;
    }
};
// @lc code=end

