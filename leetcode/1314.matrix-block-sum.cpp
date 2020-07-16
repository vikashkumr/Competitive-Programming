/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        //very basic question just logical arithmatic operation in 2d mattrix
        //dry run with example if won't understand
        // sum[i][j] represents rectangular sum of all rectangle element having index <= curr index

        //preprocessing of sum table 1 based index
        vector<vector<int>> sum(n+1, vector<int>(m+1,0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        //storing res 0 bsed index
        vector<vector<int>> res(n, vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //left row bpondry r1 //right row boundry r2
                //left col bpondry c1 //right col boundry c2
                int r1 = max(0, i-k) + 1; int r2 = min(i+k, n-1) + 1;
                int c1 = max(0, j-k) + 1; int c2 = min(j+k, m-1) + 1;
                res[i][j] = sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
            }
        }
        return res;
    }
};
// @lc code=end

