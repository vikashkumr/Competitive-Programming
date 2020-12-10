    #include<bits/stdc++.h>
    using namespace std;
    int main() {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        for(auto it : mp) {
            if(it.second>k) {
                cout<<"NO";
                exit(0);
            }
        }
        cout<<"YES";
        return 0;
    }