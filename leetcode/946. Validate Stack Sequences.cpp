//https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int idx = 0;
        stack<int> st;
        for(int i = 0;i<pushed.size();i++) {
            st.push(pushed[i]);
            while(!st.empty() and st.top()==popped[idx]) {
                st.pop();
                idx++;
            } 
        }
        return idx==popped.size() and st.empty();
    }
};