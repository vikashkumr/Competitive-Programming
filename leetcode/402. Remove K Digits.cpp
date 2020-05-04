//https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()<=k) return "0";
        stack<char>st;
        string s = "";
        for(int i=0;i<num.length();i++) {
            if(st.size()==1 and st.top()=='0'){
                st.pop();
            }
            else {
                while(!st.empty() and st.top()!=0 and k>0) {
                    if(st.top()>num[i]){
                        st.pop();k--;
                    } 
                    else 
                    break; 
                }
            }
            st.push(num[i]);
        }
        while(!st.empty() and k>0) {
            st.pop();
            k--;
        }
        while(!st.empty()) {
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};