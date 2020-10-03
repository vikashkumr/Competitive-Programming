/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') {
                st.push(i);
            }
            else if(s[i]==')') {
                if(!st.empty()) st.pop();
                else s[i]='.';
            }
        }
        string res = "";
        while(!st.empty()) {
            s[st.top()] ='.';
            st.pop();
        }
        for(int i=0;i<s.length();i++) {
            if(s[i]!='.') res += s[i];
        }
        return res;
    }
};
// @lc code=end

