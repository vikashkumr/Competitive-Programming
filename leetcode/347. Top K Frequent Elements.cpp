//https://leetcode.com/problems/top-k-frequent-elements/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int num : nums) mp[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        int cnt = 1;
        for(auto it : mp) {
            if(cnt<=k){
                pq.push({it.second, it.first});
                cnt++;
            }
            else {
                if(pq.top().first>it.second) {
                    continue;
                } else {
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};