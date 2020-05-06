//https://leetcode.com/problems/reorganize-string/
class Solution {
public:
    string reorganizeString(string S) {
        map<char,int>mp;
        string res = "";
        for(char ch: S) mp[ch]++;
        for(auto it: mp) {
            if(it.second>ceil((float) S.length()/2)) {
                return "";
            }
        }
        priority_queue<pair<int,char>>pq;
        for(auto it: mp) {
            pq.push({it.second,it.first});
        }
        while(!pq.empty() and pq.size()>1) {
            auto it1 = pq.top();pq.pop();
            auto it2 = pq.top();pq.pop();
            string temp = string(1,it1.second) + string(1,it2.second);
            while(it2.first--) {
                res+=temp;
                it1.first--;
            }
            if(it1.first>0)
            pq.push({it1.first,it1.second});
        }
        if(!pq.empty()) res+=pq.top().second;
        return res;
    }
};