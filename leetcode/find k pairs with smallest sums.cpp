// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size()==0 || nums2.size()==0 || k==0) return {};
        
        bool vis[1000][1000]={0};
        vis[0][0] = 1;
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        int cnt = 1;
        while(cnt<=k and !pq.empty()) {
            auto it = pq.top();pq.pop();
            int x = it.second.first;
            int y = it.second.second;
            if(x+1<nums1.size() and vis[x+1][y]==0) {
                vis[x+1][y] = 1;
                pq.push({nums1[x+1]+nums2[y],{x+1,y}});
            }
            if(y+1<nums2.size() and vis[x][y+1]==0) {
                vis[x][y+1] = 1;
                pq.push({nums1[x]+nums2[y+1],{x,y+1}});
            }
            ans.push_back({nums1[x],nums2[y]});
            cnt++;
        }
        return ans;
    }
};