#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 998244353
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
int n,m,K;
int dp[3001][3001];


//iterative sol
#undef int
int main(){
#define int long long 
    fast;
    
    cin>>n>>m>>K;
    dp[1][0] = m;
    FOR(i,1,n) {
        FOR(j,0,K) {
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %=mod;
            dp[i+1][j+1] += (m-1)*dp[i][j];
            dp[i+1][j+1] %=mod;
        }
    }

    cout<<dp[n][K];
    return 0;
}

//recursive solution
/*int n,m,K;
int dp[3001][3001];
int solve(int pos, int k, vector<int>arr) {
    if(pos==n) return k==K;

    int &ans = dp[pos][k];
    if(ans != -1) return ans;
    
    int op1 = 0, op2 = 0; 
    FOR(i,0,m-1) {
        arr[pos] = i;
        if(arr[pos] != arr[pos-1])
            op1 = (op1%mod + solve(pos+1, k+1, arr)%mod)%mod;
        else
            op2 = (op2%mod + solve(pos+1, k, arr)%mod)%mod; 
    }

    return ans = (op1%mod + op2%mod)%mod;
}


#undef int
int main(){
#define int long long 
    fast;
    
    cin>>n>>m>>K;
    vector<int>arr(n,-1);
    memset(dp, -1, sizeof dp);
    FOR(i,0,n-1) arr[i] = -1;
    // arr[0] = 0;
    int res = 0;
    FOR(i,0,m-1) {
        arr[0] = i;
        res=(res%mod+solve(1,0,arr)%mod)%mod;
    } 
    cout<<res;
    return 0;
}*/