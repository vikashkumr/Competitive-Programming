/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start

/*
Approach: 
    just make all boundries zero and all zero associated to that 1
    reason: they can't be considered as cosed island.
*/



class Solution {
public:
    int n, m;
    void dfs(int r, int c, vector<vector<int>>& grid) {
        if(r<0 or c<0 or r>=n or c>=m or grid[r][c]==1) return;
        grid[r][c] = 1;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        for(int i=0;i<4;i++) {
            dfs(r+dx[i], c+dy[i], grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if(grid[i][0] == 0) dfs(i,0,grid);
        }
        for (int i = 0; i < m; i++) {
            if(grid[0][i] == 0) dfs(0,i,grid);
        }
        for (int i = 0; i < n; i++) {
            if(grid[i][m-1] == 0) dfs(i,m-1,grid);
        }
        for (int i = 0; i < m; i++) {
            if(grid[n-1][i] == 0) dfs(n-1,i,grid);
        }
        
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if(grid[i][j]==0) {
                    ans++;
                    dfs(i,j,grid);        
                }
            }
        }
        return ans;
    }
};
// @lc code=end

