/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
public:
    double dp[101][101][101];
    int gr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int gc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    
    double solve(int N, int k, int r, int c) {
        
        //unbound condition
        if(r<0 || r>=N || c<0 || c>=N) return 0;
        
        if(k==0) return 1;
        double &ans = dp[k][r][c];
        if(ans != -1) return ans;
        double res = 0;
        for(int i=0;i<8;i++) {
            res += solve(N,k-1,r + gr[i],c + gc[i]);
        }
        return ans = res;
    }
    
    double knightProbability(int N, int K, int r, int c) {
        double tot_prob = pow(8,K);
        if(K==0) return 1;
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
                for(int k=0;k<101;k++)
                    dp[i][j][k] = -1;
        return solve(N,K,r,c)/tot_prob;
    }
};
// @lc code=end

