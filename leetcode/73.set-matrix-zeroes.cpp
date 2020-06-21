/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    int n, m;
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0) return;
        bool isColZero = false;
        n = matrix[0].size();

        for (int i = 0; i < m; i++) {
        // Since first cell for both first row and first column is the same i.e. matrix[0][0]
        // We can use an additional variable for either the first row/column.
        // For this solution we are using an additional variable for the first column
        // and using matrix[0][0] for the first row.
            
            if(matrix[i][0] == 0)
                isColZero = true;

            for (int j = 1; j < n; j++) {
            // If an element is zero, we set the first element of the corresponding row and column to 0
               if(matrix[i][j] == 0) {
                   matrix[i][0] = 0;
                   matrix[0][j] = 0;
               }
            }
        }

        // Iterate over the array once again and using the first row and first column, update the elements.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // See if the first row needs to be set to zero as well
        if(matrix[0][0] == 0) {
            for (int i = 0; i < n;i++)
                matrix[0][i] = 0;
        }

        // See if the first column needs to be set to zero as well
        if(isColZero) {
            for (int i = 0; i < m;i++)
                matrix[i][0] = 0;
        }

    }
};
// @lc code=end

