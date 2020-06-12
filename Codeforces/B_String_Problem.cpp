#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
#define matrix vector<vector<int> >
#define vi vector<int>
#define pii pair<int,inr>
#define vs vector<string>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//=================================================================//
int A[26][26];


void floydWarshal() {
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }
    
}

#undef int
int main(){
#define int long long 
    fast;
    string s, t;
    cin >> s >> t;
    if (s.length() != t.length()) {
        cout << -1;
    } else {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if(i==j) A[i][j] = 0;
                else A[i][j] = INT_MAX;
            }
        }
        
        int n;
        cin >> n;
        while (n--) {
            char u, v;
            int w;
            cin >> u >> v >> w;
            A[u - 'a'][v - 'a'] = min(w,A[u - 'a'][v - 'a']);
        }
        floydWarshal();
        bool ok = 1;
        int ans = 0;
        string res = s;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == t[i]) continue;
            int muchmin = INT_MAX;
            for (char ch = 'a'; ch <= 'z';ch++) {
                int tmp = muchmin;
                muchmin = min(A[s[i] - 'a'][ch - 'a'] + A[t[i] - 'a'][ch - 'a'], muchmin);
                if(muchmin < tmp) {
                    res[i] = ch;
                }
            }
            if(muchmin==INT_MAX) {
                ok = 0;
                break;
            }
            ans += muchmin;
        }
        if(ok){
            cout << ans << endl;
            cout << res << endl;
        }
        else cout << "-1" << endl;
    }

    return 0;
}