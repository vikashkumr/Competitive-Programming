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
// int dp2[3001][3001][2];
int dp1[3001][3001];

// SOLUTION 1
int solve1(int i, int j, int *arr) {
    if(i > j) return 0;

    int &ans = dp1[i][j];
    if(ans != -1) return ans;

    int op1 = arr[i] - solve1(i+1,j,arr);
    int op2 = arr[j] - solve1(i,j-1,arr);
    return ans = max(op1,op2);
}

/* SOLUTION 2
int solve2(int i, int j, int turn, int *arr) {
    if(i>j) return 0;

    int &ans = dp2[i][j][turn];
    if(ans != -1) return ans; 

    if(turn) {
        return ans = max(arr[i] + solve2(i+1, j, 0, arr), arr[j] + solve2(i,j-1, 0, arr));
    }
    else {
        return ans = min(solve2(i+1, j, 1, arr), solve2(i,j-1, 1, arr));
    }
} */
#undef int
int main(){
#define int long long 
    fast;
    cin>>n;
    int arr[n];
    int sum = 0;
    FOR(i,0,n-1) cin>>arr[i], sum+=arr[i];
    memset(dp1, -1, sizeof dp1);
    cout<<solve1(0,n-1,arr);
    // int x = solve2(0,n-1,1,arr);
    // int y = sum - x;
    // cout<<x - y;
    return 0;
}