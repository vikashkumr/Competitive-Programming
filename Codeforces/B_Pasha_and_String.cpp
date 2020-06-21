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
#define pii pair<int,int>
#define vs vector<string>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//=================================================================//


int32_t main(){
    fast;
    string s;
    cin >> s;
    int n = s.length();
    int m;
    cin >> m;
    int pre[n] = {0};
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        pre[temp - 1] += 1;
    }
    for (int i = 1; i < n;i++) {
        pre[i] += pre[i - 1];
    }

    for (int i = 0; i < n / 2; i++){
        if (pre[i] & 1){
            swap(s[i], s[n - i - 1]);
        }
    }

    cout << s;

    return 0;
}