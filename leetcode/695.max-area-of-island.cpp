/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n,m;
    int dfs(int x, int y, vector<vector<int>>&grid) {
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1) 
            return 0;
        
        int ans = 1;
        grid[x][y] = -1;
        for(int i=0;i<4;i++) {
            ans+=dfs(x+dx[i], y+dy[i], grid);
        }
        return ans;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(n==0) return 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1) {
                    ans = max(ans, dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};
// @lc code=end
