/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> ans(n);
        vector<int> g[n];
        //build graph
        for(int i = 0; i < pre.size(); i++) {
            g[pre[i][1]].push_back(pre[i][0]); 
        }
        
        vector<int> indegree(n, 0);
        //calculate indegree
        for(int i = 0; i < n; i++) {
            for(auto child: g[i]) {
                indegree[child]++;
            }
        }
        
        queue<int>q;
        //push element havign 0 indegree to the queue
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        //perform Topo step
        int k = 0;
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            ans[k++] = node;
            for(auto child: g[node]) {
                indegree[child]--;
                if(indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        
       if(k==n) return true;
        return false;
    }
};
// @lc code=end

