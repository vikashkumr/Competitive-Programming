class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(k==0) return "";
        k--;
        string res = "";
        stack<char>st;
        stack<int>cnt;
        for(char ch : s) {
            if(st.empty() or st.top()!=ch) {
                st.push(ch);
                cnt.push(1);
            }
            else {
                if(cnt.top()==k) {
                    while(!st.empty() and st.top()==ch){
                        st.pop();
                        cnt.pop();
                    }
                } else {
                    st.push(ch);
                    cnt.push(cnt.top()+1);
                }
            }
        }
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};