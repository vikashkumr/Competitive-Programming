/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int dp[(int)1e5];
    int solve(string s, int idx) {

        //BASE CASE
        if(idx == s.length()) return 1;
        if(s[idx]=='0') return 0;
        

        int &ans = dp[idx];
        if(ans != -1) return ans;
        
        //RECURSIVE CASE
        int op1 = solve(s, idx+1);
        int op2 = 0;
        if(idx<s.length()-1 and stoi(s.substr(idx,2)) <= 26) {
            op2 = solve(s, idx+2);
        }
        return ans = op1 + op2;
    }


    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s, 0);
    }
};
// @lc code=end

