// https://www.lintcode.com/problem/number-of-distinct-islands/description
// dfs+hmap // store path instring
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */

    unordered_map<string , bool> hm;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m, ref_x, ref_y;

    void dfs(int x, int y, vector<vector<int>>&grid, string &s) {
        if(x<0 || y<0 || x>=n || y>=m || !grid[x][y]) 
            return;

        grid[x][y] = 0;
        for(int i=0;i<4;i++) {
            s += to_string(x-ref_x) + to_string(y-ref_y);
            dfs(x+dx[i], y+dy[i], grid, s);
        }
        return;
    }
    
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        n = grid.size();
        m = grid[0].size();
        if(n==0) return 0;
        string res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1) {
                    string res = "";
                    ref_x = i; ref_y = j;
                    dfs(i,j,grid,res);
                    hm[res] = 1;
                }
            }
        }
        int ans = 0;
        for(auto it: hm) {
            if(it.second) {
                ans++;
            }
        }
        return ans;
    }
};