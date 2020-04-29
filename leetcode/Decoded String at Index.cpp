//https://leetcode.com/problems/decoded-string-at-index/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<pair<string, long long int>>st;
        long long int len = s.length();
        for(long long int i=0;i<len;i++) {
            string temp = "";
            while(i<s.length() and (s[i]>'9' or s[i]<'0')) {
                temp+=s[i++];
            }
            long long int l = (temp.length() + (st.empty()?0:st.top().second))*(s[i]-'0');
            st.push({temp,l});
		    if(l>=k) break;
        }
        while(!s.empty()){
		auto p = st.top();
		string x = p.first;
		long long int l = p.second;
		st.pop();

		k = k%(x.length() +(st.empty()?0:st.top().second));
		if(k == 0) k = x.length() +(st.empty()?0:st.top().second);
		if(st.empty()){
			string ans = "";
			ans += x[k-1];
			return ans;
		}
		if(k>st.top().second){
			string ans = "";
			ans += x[k-st.top().second-1];
			return ans;
		}
	}
    return "";
    }
};