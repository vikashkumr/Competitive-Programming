/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int p1 = 0;
        int p2 = 0;

        vector<vector<int>> res;
        while(p1 < firstList.size() and p2 < secondList.size()) {
            if(firstList[p1][0] <= secondList[p2][1] && secondList[p2][0] <= firstList[p1][1]) {
                res.push_back({max(firstList[p1][0], secondList[p2][0]), min(firstList[p1][1], secondList[p2][1])});
                if(firstList[p1][1] >= secondList[p2][1]) {
                    p2++;
                } else {
                    p1++;
                }
            } else if(firstList[p1][0] > secondList[p2][0]) {
                p2++;
            } else {
                p1++;
            }
        }
        return res;
    }
};
// @lc code=end

