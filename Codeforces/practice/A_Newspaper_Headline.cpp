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
#define vp vector<pii>
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int sz = 100005;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//


int32_t main(){
    fast;
    string s1, s2;
    cin>>s1>>s2;
    vi v[26];
    for(int i=0;i<s1.length();i++) {
        v[s1[i]-'a'].push_back(i);
    }
    int ans = 1, pos = -1;
    for(int i=0;i<s2.length();i++) {
        int idx = s2[i]-'a';
        if(v[idx].size()==0) {
            cout<<-1<<endl;
            exit(0);
        }
        int it = upper_bound(v[idx].begin(), v[idx].end(), pos)-v[idx].begin();
        if(it!=v[idx].size()) {
            pos = v[idx][it];
        } else {
            ans++;
            pos = v[idx][0];
        }
    }
    cout<<ans<<endl;
    return 0;
}