/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
// variation of min cost path sum

class Solution {
public:
    int n, m;
    int dp[4000][4000];
    int solve(int i, int j, vector<vector<int>>& dungeon) {
        if(i>=n or j>=m) return INT_MAX;
        if(i==n-1 and j==m-1) {
            if(dungeon[i][j] <= 0) return abs(dungeon[i][j]) + 1;
            return 1;
        }
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        return ans = max(1,min(solve(i+1, j, dungeon), solve(i, j+1, dungeon)) - dungeon[i][j]);
    }


    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        memset(dp, -1, sizeof dp);
        return solve(0,0,dungeon);
    }
};
// @lc code=end

