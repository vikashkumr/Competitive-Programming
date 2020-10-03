/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if(K>=n/2) {
            int ans = 0;
            for(int i=1;i<n;i++) {
                if(prices[i] > prices[i-1]) {
                    ans += prices[i]-prices[i-1];
                }
            }
            return ans;
        }
        int dp[1001][1001] = {0};
        for(int k=1;k<=K;k++) {
            for(int i=1;i<n;i++) {
                int ans = 0;
                for(int j=0;j<i;j++) {
                    if(prices[i] > prices[j])
                        ans = max(ans,prices[i]-prices[j] + dp[k-1][j]);
                }
                dp[k][i] = max(ans, dp[k][i-1]);
            }
        }
        return dp[K][n-1];
    }
};
// @lc code=end

