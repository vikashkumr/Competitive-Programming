/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution {
public:
    int dp[501][501];
    int solve(int st, int end, string &s) {
        if(st==end) return 0;
        if(end-st == 1) {
            if(s[st] == s[end]) return 0;
            return 1;
        }
        if(s[st] == s[end]) return solve(st+1, end-1, s);
        if(dp[st][end] != -1) return dp[st][end];
        int op1 = solve(st+1, end, s);
        int op2 = solve(st, end-1, s);
        return dp[st][end] = 1 + min(op1, op2);
    }
    
    int minInsertions(string s) {
        //two pointer
        if(s.length() <= 1) return 0;
        memset(dp, -1, sizeof dp);
        return solve(0, s.length()-1, s);
    }
};
// @lc code=end

