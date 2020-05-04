//https://leetcode.com/problems/top-k-frequent-words/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    struct comp{
        bool operator()(pair<int, string> &a, pair<int, string> &b){
            if (a.first != b.first){
                return (a.first > b.first);
            }
            else{
                return a.second < b.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> res;
        for(string word : words) mp[word]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp > pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
            if(pq.size()>k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

