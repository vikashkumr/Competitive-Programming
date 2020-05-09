//atcoder DP-1
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
typedef long double ld;
typedef vector<vector<int> > matrix;
typedef vector<int> arr;
typedef vector<string> vs;
typedef vector<pair<int,int> > pv;
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//
int dp[(int) 1e6];
int n,k;

int solve(int pos,int h[]) {
    //base case
    if(pos==n-1) return 0;
    if(pos>=n) return INT_MAX;

    int &ans = dp[pos];
    if(ans!=-1) return ans;
    //recursive case
    int op = INT_MAX;
    for(int i=1;i<=k;i++) {
        op = min(op,abs(h[pos]-h[pos+i])+solve(pos+i,h));
    }
    return ans = op;
}

#undef int
int main(){
#define int long long 
    fast;
    cin>>n>>k;
    int h[n];
    memset(dp, -1, sizeof dp);
    FOR(i,0,n-1) cin>>h[i];
    cout<<solve(0,h);
    return 0;
}