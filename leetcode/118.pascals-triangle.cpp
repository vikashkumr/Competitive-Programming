/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            res[i].push_back(1);

            for (int j = 1; j < res[i - 1].size();j++) {
                res[i].push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }

            res[i].push_back(1);
        }
        return res;
    }
};
// @lc code=end

