
//https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++) {
            mp[arr[i]]++;
        }
        int n = arr.size();
        priority_queue<int>pq;
        for(auto it : mp) {
            pq.push(it.second);
        }
        int temp = 0;
        int cnt = 0;
        while(temp<n/2) {
            temp+=pq.top();pq.pop();
            cnt++;
        }
        return cnt;
    }
};