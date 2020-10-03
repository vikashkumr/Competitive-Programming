/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string res = "";
        for(char ch: s) {
            if(ch!=']') st.push(string(1,ch));
            else {
                string tmp = "";
                while(st.top()[0]!='[') {
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop();
                string cnt_str="";
                while(!st.empty() and (st.top()[0]>='0' and st.top()[0]<='9')) {
                    cnt_str = st.top() + cnt_str;
                    st.pop();
                }
                
                int cnt = 0;
                for(int i=0;i<cnt_str.length();i++) {
                    cnt = cnt*10 + (cnt_str[i]-'0');
                }
                cnt_str = "";
                for(int i=0;i<cnt;i++)  {
                    cnt_str +=tmp;
                }
                st.push(cnt_str);
            }
        }
        while(!st.empty()) {
            res=st.top() + res;
            st.pop();
        }
        return res;
    }
};
// @lc code=end

