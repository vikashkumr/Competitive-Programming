/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
class Solution {
public:
   
    vector<int> findRightInterval(vector<vector<int>>& inter) {
        vector<pair<int,int>> v;
        int n = inter.size();
        for(int i = 0;i < n; i++) {
            v.push_back({inter[i][0], i});
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for(int i = 0; i < n; i++) {
            pair<int,int> lv({inter[i][1],0});
            int idx = lower_bound(v.begin(), v.end(), lv, [&](pair <int,int>lhs, pair<int,int> rhs) -> bool 
                                  { return lhs.first < rhs.first; })-v.begin();
            if(idx<n)
                res.push_back(v[idx].second);   
            else 
                res.push_back(-1);
        }
        return res;
    }
};
// @lc code=end

