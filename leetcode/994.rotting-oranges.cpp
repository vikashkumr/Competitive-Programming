/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int n, m;
    bool valid(int r, int c, vector<vector<int>>& grid) {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c] != 1) 
            return false;
        return true;
    }


    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int time = 0;

        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};

        while(!q.empty()) {
            bool flag = 0;
            int sz = q.size();
            for(int k=0;k<sz;k++) {
                auto node = q.front();q.pop();

                for(int i=0;i<4;i++) {
                    int x = node.first+dx[i];
                    int y = node.second+dy[i];
                    if(valid(x, y, grid)) {
                        grid[x][y] = 2;
                        q.push({x,y});
                        flag = 1;
                    }
                }
            }
            if(flag)
            time++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
// @lc code=end

