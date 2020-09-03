// https://leetcode.com/problems/maximal-square/


class Solution {
public:
    int max(int a,int b) {
        return a>b?a:b;
    }
    
    int maximalSquare(vector<vector<char>>& m) {
        int n = matrix.size();
        int m = matrix[0].size();
   		int dp[n][m]={0};
        int ans = 0;
        for(int i=0;i<m;i++) if(matrix[0][i] == '1') dp[0][i] = 1, ans = 1;
		for(int i=0;i<n;i++) if(matrix[i][0] == '1') dp[i][0] = 1, ans = 1;
        for(int i=1;i<n;i++) {
        	for(int j=1;j<m;j++) {
            	if(matrix[i][j] == '1')  {
                	dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1],dp[i][j-1]));
                	ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};