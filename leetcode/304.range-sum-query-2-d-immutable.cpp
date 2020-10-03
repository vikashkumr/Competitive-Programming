/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> v;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        v = matrix;
        n = matrix.size();
        if(n>=1)
        m = matrix[0].size();
        for(int i=1;i<m;i++) {
            v[0][i] += v[0][i-1];       
        }
        for(int i=1;i<n;i++) {
            v[i][0] += v[i-1][0];       
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                v[i][j]+=v[i-1][j] + v[i][j-1] - v[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(n==0) return 0;
        return v[row2][col2] - ((row1-1>=0) ? v[row1-1][col2] : 0) - ((col1-1>=0) ? v[row2][col1-1] : 0) + ((row1>0 and col1>0) ?v[row1-1][col1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

