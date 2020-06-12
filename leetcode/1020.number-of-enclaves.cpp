/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:
    int row, col;

    void dfs(vector<vector<int>>& A, int i, int j) {
        if(i<0 or j<0 or i>=row or j>=col) return;
        if(A[i][j]==0 or A[i][j]==-1) return;
        A[i][j] = -1;
        dfs(A,i+1,j);
        dfs(A,i,j+1);
        dfs(A,i,j-1);
        dfs(A,i-1,j);
    }


    int numEnclaves(vector<vector<int>>& A) {
        row = A.size();
        col = A[0].size();
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++){
                if(i==0 or j==0 or i==row-1 or j==col-1) {
                    dfs(A,i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(A[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

