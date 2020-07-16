/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 or matrix[0].size()==0) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m-1;
        while(i<n and j>=0) {
            if(matrix[i][j]==target) return true;
            if(matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};
// @lc code=end

