/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int solve(int i, int j, string &s, string &t,vector<vector<int>>&dp) {
        //base
        if(j==t.length()) return 1;
        if(i==s.length()) return 0;
        if(i<j) return 0;
        
        
        int &res = dp[i][j];
        if(res != -1) return res;
        
        //recursive
        int ans;
        if(s[i]==t[j]) {
            ans = solve(i+1,j+1,s, t,dp) + solve(i+1,j, s,t,dp);
        } else {
            ans = solve(i+1,j,s,t,dp);
        }
        
        return res = ans; 
    }
    
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
        if(s.length() < t.length()) return 0;
        return solve(0,0,s,t,dp);
    }
};
// @lc code=end

