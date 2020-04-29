//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
//to reduce time reverse function on string, use stack only to keep track of opening and closing brackets

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string res = "";
        for(char ch : s) {
            if(ch!=')') st.push(ch);
            else {
                string temp="";
                while(st.top()!='(') {
                    temp = temp+st.top();
                    st.pop();
                }
                st.pop();
                for(char c : temp) {
                    st.push(c);
                }
            }
        }
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};