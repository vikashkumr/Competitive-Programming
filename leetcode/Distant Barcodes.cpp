
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int num : barcodes) mp[num]++;
        priority_queue<pair<int,int>> pq;
        for(auto it : mp) pq.push({it.second,it.first});
        for(int i=0;i<barcodes.size();i++) {
            if(i>0 and res[i-1]==pq.top().second) {
                auto it1 = pq.top();pq.pop();
                res.push_back(pq.top().second);
                auto it2 = pq.top();pq.pop();
                pq.push(it1);
                int x = it2.first-1;
                if(x>0)
                pq.push({x,it2.second});
            } else {
                auto it = pq.top();pq.pop();
                res.push_back(it.second);
                int x = it.first-1;
                if(x>0)
                pq.push({x,it.second});
            }
        }
        return res;
    }
};