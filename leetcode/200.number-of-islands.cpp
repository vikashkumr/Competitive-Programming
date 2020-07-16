class Solution {
public:
    int n,m;
    void dfs(int r, int c, vector<vector<char>>& grid) {
        if(r<0 or r>=n or c<0 or c>=m or grid[r][c]=='0') return;
        grid[r][c] = '0';
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c-1,grid);
        dfs(r,c+1,grid);
    }


    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]=='1') {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};