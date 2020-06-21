/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [&](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int dp[n];
        for (int i = 0; i < n;i++) dp[i] = 1;
            for (int i = 1; i < n; i++) {
                int mx = -1;
                for (int j = i - 1; j >= 0; j--) {
                    if (pairs[j][1] < pairs[i][0]) {
                        mx = max(mx, dp[j]);
                    }
                }
                if (mx != -1) {
                    dp[i] += mx;
                }
            }
        int ans = -1;
        for (int i = 0; i < n;i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

