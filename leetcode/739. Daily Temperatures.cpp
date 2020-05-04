//https://leetcode.com/problems/daily-temperatures/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        unordered_map<int,int> mp;
        stack<int>st;
        vector<int> v;
        for(int i=0;i<T.size();i++) {
            while(!st.empty() and T[st.top()]<T[i]) {
                int ans = i-st.top();
                mp[st.top()] = ans;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<T.size();i++) {
            if(mp[i]!=0) v.push_back(mp[i]);
            else v.push_back(0);
        }
        return v;
    }
};