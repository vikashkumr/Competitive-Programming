/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    string s1,s2,s;
    int dp[200][200][400];
    bool solve(int pos1, int pos2, int pos) { 
        if(pos1==-1 and pos2==-1 and pos==-1) {
            return true;
        }
        if(pos==-1) return false;
        if(pos1>=0 and pos2>=0) {
            if(dp[pos1][pos2][pos] != -1) return dp[pos1][pos2][pos];
        }
        
        bool op1 = false, op2 = false;
        if(pos1 >= 0 and s1[pos1] == s[pos]) op1 = solve(pos1-1, pos2, pos-1);
        if(pos2 >= 0 and s2[pos2] == s[pos]) op2 = solve(pos1, pos2-1, pos-1);
        if(pos1>=0 and pos2>=0) return dp[pos1][pos2][pos] = op1 || op2;
        else 
        return  op1 || op2;
    }

    bool isInterleave(string s1i, string s2i, string si) {
        s1 = s1i;
        s2 = s2i;
        s = si;
        memset(dp, -1, sizeof dp);
        return solve(s1.length()-1,s2.length()-1,s.length()-1);
    }
};
// @lc code=end

