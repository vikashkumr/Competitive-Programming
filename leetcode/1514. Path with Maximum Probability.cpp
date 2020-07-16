class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i = 0;i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        queue<pair<int,double>> q;
        q.push({start, 1.0});
        
        double vis[20001] = {0};
        double ans = 0.0;
        
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            for(auto child: adj[curr.first]) {
                if(vis[child.first] < curr.second*child.second and child.first!=end) {
                    vis[child.first] = curr.second*child.second;
                    q.push({child.first,curr.second*child.second});
                } else if(child.first == end) {
                    ans = max(ans,curr.second*child.second);   
                }
            }
        }
        
        return ans;
     }
};