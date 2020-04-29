//https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string S) {
        int cnt = 0;
        string res = "";
        stack<char>st;
        for(char ch : S) {
            if(st.empty()) {
                cnt = 1;
                st.push(ch);
            } else if(ch=='(') {
                st.push('(');
                cnt++;
            } else {
                st.push(')');
                cnt--;
                if(cnt==0) {
                    st.pop();
                    string temp = "";
                    while(st.size()!=1) {
                        // res=st.top()+res;
                        temp = st.top()+temp;
                        st.pop();
                    }
                    res+=temp;
                    st.pop();
                }
            }
        }
        return res;
    }
};