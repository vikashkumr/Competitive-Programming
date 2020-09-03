/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Sequence
 */

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
         //Solution 1
       /* map<pair<int,int>, int> hm;
        int n = A.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
               int d =  A[i]-A[j];  
               hm[{i,d}] = max(hm[{i,d}], hm[{j,d}]+1);
            }
        }
        int ans = 0;
        for(auto it: hm) {
           ans = max(ans, it.second);
        }
        
        return ans + 1;  */
        
        //Solution 2
        
        int n = A.size();
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = A[i] - A[j];
                ans = max(ans, dp[i][diff] = max(dp[j][diff], 1) + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

