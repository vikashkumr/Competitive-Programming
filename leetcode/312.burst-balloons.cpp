/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& num) {
        int dp[501][501]={0};
        int n = num.size();
        vector<int> nums(n+2,0);
        for(int i=0;i<n;i++) nums[i+1] = num[i];
        nums[0] = 1; nums[n+1] = 1;
        // for(int i=1;i<=n;i++) dp[i][i] = nums[i-1];
        
        for(int L = 1; L<=n;L++) {
            for(int i=1;i<=n-L+1;i++) {
                int j = i+L-1;
                dp[i][j] = INT_MIN;
                for(int pivot = i;pivot<=j;pivot++) {
                    dp[i][j] = max(dp[i][j], dp[i][pivot-1] + nums[i-1]*nums[pivot]*nums[j+1] + dp[pivot+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};

// @lc code=end

