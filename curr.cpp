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
int n;
int dp[1001][1001];
int solve(int pos, int *arr, int last_pos) { 

    int &ans = dp[pos][last_pos];
    if(ans != -1) return ans;

    int val = 0;
    for(int i=pos;i<n;i++) {
        if((arr[i]%arr[last_pos])==0)
        val = max(val, arr[i] + solve(i+1, arr, i));
    }
    return ans = val;
}

int32_t main(){
    fast;
    n = 6;
    int arr[n] = {1,2,3,4,9,8};
    int ans = 0;
    memset(dp, -1, sizeof dp);
    for(int i=0;i<n;i++) {
        ans = max(ans, arr[i] + solve(i+1, arr, i));
    }
    cout<<ans;
    return 0;
}