//https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        int dp[1001][1001];
        memset(dp, -1, sizeof dp);
        for(int i=0;i<=A.length();i++) dp[i][0] = 0;
        for(int i=0;i<=B.length();i++) dp[0][i] = 0;
        for(int i=1;i<=A.length();i++) {
            for(int j=1;j<=B.length();j++) {
                if(A[i-1]==B[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }    
        return dp[A.length()][B.length()];
    }
};