/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int dp[n];
        int f[n];
        fill(f, f + n, 1);
        // f[0] = 1;
        fill(dp, dp + n, 1);
        for (int i = 1; i < n; i++) {
            int mx = -1;
            for (int j = i-1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    mx = max(mx, dp[j]);
                }
            }
            if(mx != -1) {
                dp[i]+=mx;
                for (int j = i - 1; j >= 0; j--) {
                    if(nums[j]<nums[i] and dp[j]==mx) f[i]+=(f[j]-1);
                }
            }
        }
        int ans = -1;
        for(int x: f) {
            cout << x << " ";
            ans = max(ans, x);
        }
        return ans;
    }
};
// @lc code=end

