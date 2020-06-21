/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// @lc code=start
/*
key point to note ans is always possible given.

approach: 
     keep two variable left_max and curr_max, at any time we have to keep
        left subarray element < element in right subarray
    if we encounter element >= left_max continue because this may or may not be the element of right subarray
variable: 
    left_max = max element till now in left array
    curr_max = as name says curr max till ith instant

*/

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        int left_max = A[0];
        int curr_max = A[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            curr_max = max(curr_max, A[i]);
            if (A[i] < left_max) {
                ans = i;
                left_max = curr_max;
            }
        }
        return ans + 1;
    }
};
// @lc code=end

