//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        bool vis[1000][1000]={0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq;
        pq.push({matrix[0][0],{0,0}});
        k--;
        vis[0][0] = 1;
        while(k--) {
            auto it = pq.top();
            int i = it.second.first;
            int j = it.second.second;
            if(i<n and j+1<n and vis[i][j+1]==0) {
                pq.push({matrix[i][j+1],{i,j+1}});
                vis[i][j+1]=1;
            }
            if(i+1<n and j<n and vis[i+1][j]==0) {
                pq.push({matrix[i+1][j],{i+1,j}});
                vis[i+1][j]=1;
            }
            pq.pop();
        }
        return pq.top().first;
    }
};