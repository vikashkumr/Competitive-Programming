//https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size()==0) return {};
        map<int,int>mp; //idx to indexes
        stack<int> st;//keep indexes
        int n = nums.size();
        int ans = INT_MIN;
        int mid;
        for(int i=0;i<n;i++) {
            if(nums[i]>=ans) {
                mid = i;
                ans = nums[i];
            }
        }
        mp[mid] = -1;
        for(int i=(mid+1)%n;i!=mid;i = (i+1)%n) {
            if(st.empty()) {
                st.push(i);
            } 
            else if(nums[st.top()]>=nums[i])
                st.push(i);
            else {
                while(!st.empty() && nums[st.top()]<nums[i]) {
                    mp[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty() && nums[st.top()]<nums[mid]) {
            mp[st.top()] = mid;
            st.pop();
        }
        
        while(!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }
        
        vector<int> v;
        for(auto it: mp) {
            if(it.second==-1)
            v.push_back(it.second);
            else v.push_back(nums[it.second]);
        }
        
        return v; 
    }
};