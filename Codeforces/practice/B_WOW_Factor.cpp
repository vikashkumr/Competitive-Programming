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
    string s;
    cin>>s;
    int n = s.length();
    int pre[n]={0}, suffi[n]={0};
    for(int i=1;i<n;i++) {
        if(s[i-1]==s[i] and s[i] == 'v') {
            pre[i]=pre[i-1]+1;
        } else {
            pre[i] = pre[i-1];
        }
    }
    for(int i=n-2;i>=0;i--) {
        if(s[i]==s[i+1] and s[i] == 'v') {
            suffi[i]=suffi[i+1]+1;
        } else {
            suffi[i] = suffi[i+1];
        }
    }
    int ans = 0;
    for(int i=1;i<n-1;i++) {
        if(s[i]=='o') {
            ans+=pre[i-1] * suffi[i+1];
        }
    }
    cout<<ans;
    return 0;
}