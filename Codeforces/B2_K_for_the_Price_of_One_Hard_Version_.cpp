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
\
#undef int
int main(){
#define int long long 
    fast;
    test() {

        int n,p,k;
        cin>>n>>p>>k;
        int arr[n];
        FOR(i,0,n-1) cin >> arr[i];
        sort(arr,arr+n);
        int dp[n]={0};
        FOR(i,0,n-1) {
            if(i<k-1) {
                 dp[i] = arr[i] + (i==0?0:dp[i-1]);
                
            } else if(i==k-1) {
                dp[i] = arr[i];
            } 
            else {
               dp[i] = dp[i-k] + arr[i];
            }
        }
        int ans = 0;
        FOR(i,0,n-1) {
            if(dp[i]<=p) ans = i+1;
        }

        cout<<ans<<endl;
    }
    
    return 0;
}