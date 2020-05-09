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
int n;

int solve(int pos,int h[]) {
    //base case
    if(pos==n-1) return 0;
    if(pos>=n) return INT_MAX;

    int &ans = dp[pos];
    if(ans!=-1) return ans;
    //recursive case
    int op1 = INT_MAX, op2 = INT_MAX;
    if(pos+1<n)
        op1 = abs(h[pos]-h[pos+1]) + solve(pos+1,h);
    if(pos+2<n)
        op2 = abs(h[pos]-h[pos+2]) + solve(pos+2,h);

    return ans = min(op1,op2);

}

#undef int
int main(){
#define int long long 
    fast;
    cin>>n;
    int h[n];
    memset(dp, -1, sizeof dp);
    FOR(i,0,n-1) cin>>h[i];
    cout<<solve(0,h);
    return 0;
}