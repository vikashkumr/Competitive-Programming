/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start

//LCS variant
class Solution {
public:
    int dp[1000][1000];
    
    int solve(int i, int j, string &s1, string &s2) {
        
        int &res = dp[i][j];
        if(res != -1) return res;
        
        //base case
        
        if(i >= s1.length()) {
            int ans = 0;
            for(int k=j;k<s2.length();k++) ans+=s2[k];
            return res = ans;
        }

        if(j >= s2.length()) {
            int ans = 0;
            for(int k=i;k<s1.length();k++) ans+=s1[k];
            return res = ans;
        }
        
        //recursive case
        
        if(s1[i]==s2[j]) return res = solve(i+1,j+1,s1,s2);
        int op1 = s1[i] + solve(i+1, j, s1, s2);
        int op2 = s2[j] + solve(i, j+1, s1, s2);

        return res = min(op1, op2);
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof dp);
        return solve(0,0, s1, s2);
    }
};
// @lc code=end

