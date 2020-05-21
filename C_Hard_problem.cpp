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
int energy[100001];
int n;
int dp[100001];
int solve(int pos,string arr[]) {
    if(pos == n) return 0;
    string *t = arr;
    int &ans = dp[pos];
    if(ans!=-1) return ans;
    
    int op1 = INT_MAX;
    int op2 = INT_MAX;
    if(pos>0 and t[pos]>=t[pos-1]) {
        op1 = solve(pos+1,t);
    }
    string temp = t[pos];
    reverse(temp.begin(),temp.end());
    if(pos>0 and temp>=t[pos-1]) {
        reverse(t[pos].begin(),t[pos].end());
        op2 = energy[pos] + solve(pos+1,t);
    }

    return ans =  min(op1,op2);
}


#undef int
int main(){
#define int long long 
    fast;
    cin>>n;
    FOR(i,0,n-1) cin>>energy[i];
    string str[n];
    FOR(i,0,n-1) cin>>str[i];
    memset(dp, -1, sizeof dp);
    int ans1 = solve(1, str);
    reverse(str[0].begin(),str[0].end());
    memset(dp, -1, sizeof dp);
    int ans2 = solve(1, str) + energy[0];
    if(min(ans1,ans2)==INT_MAX) cout<<-1;
    else cout<<min(ans1, ans2);
    return 0;
}
