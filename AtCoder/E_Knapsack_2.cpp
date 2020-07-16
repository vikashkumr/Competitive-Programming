#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
#define matrix vector<vector<int> >
#define vi vector<int>
#define pii pair<int,int>
#define vs vector<string>
#define vp vector<pii>
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end() 
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int sz = 100005;
//=================================================================//
int *weight, *prices;
int n, capacity;
int dp[101][sz];    //n * (profit) // total profit could be n * given profit


int knapsack2(int mx_profit) {
    int inf = 1e11;
    for(int N=0;N<=n;N++) {
        for(int profit=0;profit<=mx_profit;profit++) {
            if(N==0 and profit==0) dp[N][profit] = 0;
            else if(N==0) dp[N][profit] = inf;
            else if(prices[N-1]<=profit) {
                dp[N][profit] = min(weight[N-1] + dp[N-1][profit-prices[N-1]], dp[N-1][profit]);
            } else {
                dp[N][profit] = dp[N-1][profit];
            }
        }
    }
    int ans = 0;
    for(int profit=0;profit<=mx_profit;profit++) {
        if(dp[n][profit]<=capacity) ans = profit;
    }
    return ans;
}


int32_t main(){
    fast;
    cin>>n>>capacity;
    weight = new int[n];
    prices = new int[n];
    int mx_profit = 0;
    for(int i=0;i<n;i++) {
        cin>>weight[i]>>prices[i];
        mx_profit += prices[i];    
    }
    
    cout<<knapsack2(mx_profit);
    return 0;
}