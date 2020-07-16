/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    void dfs(vector<vector<int>>& image, int cur_color, int new_color, int r, int c) {
        if(r<0 or r>=image.size() or c<0 or c>=image[0].size() or (image[r][c]!=cur_color or cur_color==new_color)) return;

        image[r][c] = new_color;
        for(int i=0;i<4;i++) {
            dfs(image,cur_color, new_color,r+dx[i],c+dy[i]);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty()) return {};
        int curr_color = image[sr][sc];
        dfs(image,curr_color,newColor,sr,sc);
        return image;
    }
};
// @lc code=end

