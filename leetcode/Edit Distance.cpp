//EDIT DISTANCE
//https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string w1, string w2) {
        int l1 = w1.length() + 1;
        int l2 = w2.length() + 1;
        int dp[l1][l2];
        for(int i=0;i<=w1.length();i++) {
            for(int j=0;j<=w2.length();j++) {
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else if(w1[i-1] == w2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[w1.length()][w2.length()];
    }
};