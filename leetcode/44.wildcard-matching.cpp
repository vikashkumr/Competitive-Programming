/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
/*
    see dp recurrance relation 
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[2005][2005];
        int slen = s.size();
        int plen = p.size();
        dp[0][0] = true;
        
        for(int i=1;i<=slen;i++) {
            dp[0][i] = false;
        }
        for(int i=1;i<=plen;i++) {
            if(p[i-1]=='*' and dp[i-1][0]) dp[i][0] = true;
            else dp[i][0] = false;
        }

        for (int i = 1; i <= plen; i++) {
            for (int j = 1; j <= slen; j++) {
                if(p[i-1]=='*' and (dp[i][j-1] or dp[i-1][j])) {
                    dp[i][j] = true;
                } else if(p[i-1]==s[j-1] or p[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[plen][slen];
    }
};
// @lc code=end

