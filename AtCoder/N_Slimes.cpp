#include<bits/stdc++.h>
using namespace std;
#define int long long 
long long inf = 4654354313333345;
//=================================================================//
int dp[3001][3001];
int sum[3001][3001];
int solve(vector<int>&v, int i, int j) {
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int minCost = inf;
    for(int k = i;k<j;k++) {
        minCost = min(minCost,sum[i][j]+solve(v,i,k)+solve(v,k+1,j));
    }
    return dp[i][j] = minCost;
}

void preprocess(vector<int>&v, int n) {
    for(int i = 1;i<=n;i++) {
        for(int j = i;j<=n;j++) {
            sum[i][j] = v[j] + ((j==i) ? 0 :sum[i][j-1]);
        }
    }
}

#undef int
int main(){
#define int long long 
    int n;
    cin>>n;
    memset(dp, -1, sizeof dp);
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    preprocess(v,n);
    cout<<solve(v,1,n);
    return 0;
}