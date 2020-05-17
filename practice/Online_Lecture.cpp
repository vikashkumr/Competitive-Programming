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
int n,sum;
int dp[200][200];
int solve(int pos,int s, int *arr) {
    if(pos==n and s==sum) return 1;
    if(s==sum) return 1;
    if(pos==n) return 0;
    if(s>sum) return 0;

    int &ans = dp[pos][s];
    if(ans != -1) return ans;

    int op1 = solve(pos+1,s+arr[pos],arr);
    int op2 = solve(pos+1,s,arr);
    return ans = op1+op2;
}


#undef int
int main(){
#define int long long 
    fast;
    test() {
        cin>>n>>sum;
        memset(dp, -1, sizeof dp);
        int arr[n];
        FOR(i,0,n-1) cin>>arr[i];
        cout<<solve(0,0,arr)<<endl;
    }
    
    return 0;
}