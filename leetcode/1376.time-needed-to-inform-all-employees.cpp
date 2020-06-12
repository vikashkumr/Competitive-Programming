/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution {
public:
    void dfs(int z, unordered_map<int,vector<int>> &g, vector<int>& informTime, int &res, int curr) {
        curr += informTime[z];
 		res = max(res, curr);
        for(auto it: g[z]) {
            dfs(it,g,informTime,res,curr);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> g;
        for(int i=0;i<manager.size();i++) {
            if(manager[i]!=-1)
            g[manager[i]].push_back(i);
        }
        int curr = 0, res = 0;
        dfs(headID,g,informTime,res,curr);
        return res;
    }
};
// @lc code=end

