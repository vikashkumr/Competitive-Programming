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

int dp[100001][3];
int solve(int pos,int i, int arr[][3]) {
    if(pos==n) return 0;

    //recursive case
    int &ans = dp[pos][i];
    if(ans != -1) return ans;

    int op1 = arr[pos][i] + solve(pos+1,(i+1)%3,arr); 
    int op2 = arr[pos][i] + solve(pos+1,(i+2)%3,arr);
    return ans = max(op1,op2);
}

#undef int
int main(){
#define int long long 
    fast;
    cin>>n;
    int arr[n][3];
    FOR(i,0,n-1) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    memset(dp, -1, sizeof dp);
    int ans1 = solve(0,0,arr);
    int ans2 = solve(0,1,arr);
    int ans3 = solve(0,2,arr);
    cout<<max(ans1,max(ans2,ans3));
    
    return 0;
}