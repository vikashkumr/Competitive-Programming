//https://leetcode.com/problems/next-greater-element-ii/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       unordered_map<int,int> mp;
       stack<int> st;
       vector<int>v;
       st.push(0);
       int i = 1;
       while(!st.empty()) {
           if(i==st.top()) {
               break;
           }
           else if(nums[i]<=nums[st.top()]){
               st.push(i);
               i=(i+1)%nums.size();
           } else {
               while(nums[st.top()]<nums[i]) {
                   mp[st.top()] = i;
                   st.pop();
               }
               st.push(i);
               i=(i+1)%nums.size();
           }
       }
        while(!st.empty()) {
            v.push_back(-1);
            st.pop();
        }
        for(auto it : mp) {
            v.push_back(nums[it.second]);
        }
    }
};