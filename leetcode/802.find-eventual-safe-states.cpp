/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int> &vis) {
        if(vis[i]) {
            return vis[i] == 1;
        }
        vis[i] = -1;
        for(auto x : graph[i]) {
            if(!dfs(x,graph,vis)) {
                return false;
            }
        }
        vis[i] = 1;
        return true;
    }




    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> res;

        for(int i=0;i<n;i++) {
            if(dfs(i,graph,vis)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

