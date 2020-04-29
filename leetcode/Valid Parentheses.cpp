//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch : s) {
            if(st.empty() or ch=='(' or ch=='{' or ch=='[') st.push(ch);
            else {
                if(ch==')' and st.top()=='(') st.pop();
                else if(ch=='}' and st.top()=='{') st.pop();
                else if(ch==']' and st.top()=='[') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};