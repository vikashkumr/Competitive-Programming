/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        while(i<n && intervals[i][1] < newInterval[0]) res.push_back(intervals[i++]);
        
        vector<int> mergeI = newInterval;
        while(i<n && intervals[i][0] <= newInterval[1]) {
            mergeI[0] = min(intervals[i][0], mergeI[0]);
            mergeI[1] = max(intervals[i][1], mergeI[1]);
            i++;
        }
        
        res.push_back(mergeI);
        while(i < n) res.push_back(intervals[i++]);
        return res;
    }
};
// @lc code=end

