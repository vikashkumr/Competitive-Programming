/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[1001][1001] = {0};
        
        int cnt = 0;
        //process 1 ength string
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;
            cnt++;        
        }

        //process 2 length string

        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]) dp[i][i+1] = 1, cnt++;
            else dp[i][i+1] = 0;       
        }


        //general
        for(int len=3;len<=n;len++) {
            for(int i=0;i<=n-len;i++) {
                int j = i+len-1;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1], cnt+=dp[i+1][j-1];
                else dp[i][j] = 0;
            }
        }

        return cnt;
    }
};
// @lc code=end

