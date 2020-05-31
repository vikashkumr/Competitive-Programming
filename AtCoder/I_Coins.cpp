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
int n;
double dp[3000][3000];
double solve(int pos, int heads, double *p) {
    //base case
    if(pos == n) return (heads >= (n+1)/2);
    if(heads >= (n+1)/2) return 1;

    double &ans = dp[pos][heads];
    if(ans != -1) return ans;

    //recursive case
    //choose head
    double op1 = p[pos]*solve(pos+1,heads+1,p);
    //choose tail
    double op2 = (1-p[pos])*solve(pos+1,heads,p);
    return ans = op1 + op2;
}

#undef int
int main(){
#define int long long 
    fast;
    cin>>n;
    double p[n];
    FOR(i,0,n-1) cin>>p[i];
    FOR(i,0,2999)
        FOR(j,0,2999)
            dp[i][j] = -1.0;
    cout<<fixed<<setprecision(10)<<solve(0,0,p);
    return 0;
}