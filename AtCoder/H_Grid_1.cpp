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
int dp[1001][1001];
char mat[1001][1001];
int n,m;
int solve(int i, int j) {
    //base case
    if(i>=n || j>=m || mat[i][j]=='#') return 0;
    if(i==n-1 && j==m-1) return 1;

    //recursive case
    int &ans = dp[i][j];
    if(ans != -1) return ans%mod;

    return ans = (solve(i, j+1)%mod + solve(i+1,j)%mod)%mod;

}


#undef int
int main(){
#define int long long 
    fast;

    cin>>n>>m; 
    memset(dp, -1, sizeof dp);
    FOR(i,0,n-1) {
        FOR(j,0,m-1)
            cin>>mat[i][j];
    }
    cout<<solve(0,0)%mod;
    return 0;
}   