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
int dp[101][100001];
int KS(int *weight, int *price,int N, int W) {
    if(N==0 || W==0) return 0;

    int &ans = dp[N][W];
    if(ans != -1) return ans;

    int op1 = INT_MIN, op2 = INT_MIN;
    if(weight[N]<=W)
    op1 = price[N] + KS(weight, price, N-1, W-weight[N]);
    op2 = KS(weight, price, N-1, W);

    return ans = max(op1,op2);
} 


#undef int
int main(){
#define int long long 
    fast;
    int Ni,Wb;
    cin>>Ni>>Wb;
    int weight[Ni+1], val[Ni+1];
    FOR(i,1,Ni) cin>>weight[i]>>val[i];
    
    memset(dp, -1, sizeof dp);
    cout<<KS(weight, val, Ni, Wb);
    return 0;
}
