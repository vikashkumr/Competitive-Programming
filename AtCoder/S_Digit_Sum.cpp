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
int dp[10001][101][2];
string s;
int D;
int solve(int pos,int sum, int tight) {
    if(pos==s.length()) {
        return (sum%D)==0;
    }

    int &ans = dp[pos][sum][tight];
    if(ans != -1) return ans;

    int res = 0;
    int end = (tight) ? (s[pos]-'0') : 9;
    for(int i=0; i<=end; i++) {
        (res += (solve(pos+1,(sum+i)%D, tight&(i==end))%mod)%mod);
    }
    return ans = res%mod;
}


#undef int
int main(){
#define int long long 
    fast;
    cin>>s>>D;
    memset(dp, -1, sizeof dp);
    int ans = solve(0,0,1);
    cout<<(ans-1+mod)%mod<<endl;
    return 0;
}