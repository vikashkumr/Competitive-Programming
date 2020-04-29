//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> mp;
        vector<int> res;
        if(nums1.size()==0) return res;
        if(nums1.size()==0 and nums2.size()==0) return res;
        st.push(nums2[0]);
        for(int i=1;i<nums2.size();i++) {
            if(st.empty()) {
                st.push(nums2[i]);
            } else {
                if(nums2[i]>st.top()) {
                    while(!st.empty()) {
                        if(st.top()<nums2[i]) {
                            mp[st.top()] = nums2[i]; st.pop();
                        } else {
                            st.push(nums2[i]);
                            break;
                        }
                    }
                    if(st.empty()) {
                        st.push(nums2[i]);
                    }
                } else {
                    st.push(nums2[i]);
                }
            }
        }
        while(!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }
        
        for(int x : nums1) {
            res.push_back(mp[x]);
        }
        return res;
    }
};