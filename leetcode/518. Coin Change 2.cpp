//https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int dp[500][5001];

    int change(int amount, vector<int>& coins) {
        for(int i=0;i<=coins.size();i++) dp[i][0] = 1;
        for(int i=1;i<=coins.size();i++) {
            for(int j=1;j<=amount;j++) {
                if(j<coins[i-1]) dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[coins.size()][amount]; 
    }
};