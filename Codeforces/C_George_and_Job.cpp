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
int n,m,k;
int dp[5001][5001];
int solve(int pos, int k_cnt, int *arr) {
    //base case
    if(k_cnt>=k) return 0;
    if(pos > n-m) return 0; 


    int &ans = dp[pos][k_cnt];
    if(ans != -1) return ans;

    //recursive case
    int op1 = 0, op2 = 0;
    if(pos<=n-m) {
        for(int i=pos;i<pos+m;i++) op1+=arr[i];
        op1+=solve(pos+m,k_cnt+1,arr);
    }
    op2 += solve(pos+1,k_cnt,arr);
    return ans = max(op1,op2);
}


#undef int
int main(){
#define int long long 
    fast;
    cin>>n>>m>>k;
    int arr[n];
    FOR(i,0,n-1) cin>>arr[i];
    memset(dp, -1, sizeof dp);
    cout<<solve(0, 0, arr);
    return 0;
}