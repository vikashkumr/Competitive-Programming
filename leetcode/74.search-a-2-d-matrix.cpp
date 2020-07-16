/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        if(m==0) return false;
        if(matrix[0][0] > target || matrix[n-1][m-1] < target) return false;
        
        bool ans = false;
        for(int i=0;i<n;i++) {
            if(matrix[i][0] > target) return false; 
            if(matrix[i][m-1] < target) continue;
            return binary_search(matrix[i].begin(),matrix[i].end(), target);
        }

        return ans;
    }
};
// @lc code=end

