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

int deleteAndEarn(vector<int>& nums) {
    map<int,int> mp;
    int mx=-1;
    for(int num : nums) {
        mx = max(mx,num);
        mp[num]++; 
    }
    int dp[100001]={0};
    int ans = 0;
    dp[0] = 0;
    dp[1] = mp[1];
    ans = max(ans,dp[1]);
    for(int i=2;i<=mx;i++) {
        dp[i] = max(dp[i-1],i*mp[i]+dp[i-2]);
        ans = max(ans,dp[i]);
    }
    return ans;        
}


#undef int
int main(){
#define int long long 
    fast;
    cin>>n;
    vector<int>nums(n);
    FOR(i,0,n-1) cin>>nums[i];
    cout<<deleteAndEarn(nums);
    return 0;
}