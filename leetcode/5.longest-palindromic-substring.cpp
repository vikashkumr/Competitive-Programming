/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[1001][1001];
        memset(dp, 1, sizeof dp); //either use all 1's initialized array or start algo from len = 3
        int l = 0;
        int r = 0;

        //process 1 length string
        for(int i=0;i<n;i++) {
            dp[i][i] = 1;     
        }

        //process 2 length string

        // for(int i=0;i<n-1;i++) {
        //     if(s[i]==s[i+1]) dp[i][i+1] = 1,l = i, r=i+1;
        //     else dp[i][i+1] = 0;       
        // }


        //general algorithm
        for(int len=2;len<=n;len++) { //len will start from 3 if process 2 is comment out and memset comment in
            for(int i=0;i<=n-len;i++) {
                int j = i+len-1;
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                    if(dp[i+1][j-1] and (j-i>r-l)) l = i, r = j; //updating first and last index of substr
                }
                else dp[i][j] = 0;
            }
        }
        
        return s.substr(l,r-l+1);
    }
};
// @lc code=end