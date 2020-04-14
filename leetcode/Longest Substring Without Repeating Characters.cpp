class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set<char>st;
    int ans=0;
    int maxAns=INT_MIN;
    for(int i=0;i<s.length();++i){
        st.clear();
        ans=1;
        st.insert(s[i]);
        for(int j=i+1;j<s.length();++j){
            if(st.find(s[j])==st.end()){
                ++ans;
                st.insert(s[j]);
            }
            else {
                maxAns = max(ans,maxAns);
                break;
            }
            maxAns = max(ans,maxAns);
        }
    }
    return max(maxAns,ans);
    }
};