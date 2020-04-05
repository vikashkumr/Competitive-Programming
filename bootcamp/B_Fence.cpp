#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>> n >> k;
    int h[n];
    for(int i=0;i<n;i++) cin>>h[i];
    int dp[n+1];
    dp[0] = 0;
    dp[1] = h[0];
    for(int i=2;i<=n;i++) {
        dp[i] = h[i-1] + dp[i-1];
    }
    int ans = INT_MAX;
    int idx;
    for(int i = k;i<=n;i++) {
        if(dp[i]-dp[i-k]<ans){
            ans = dp[i]-dp[i-k];
            idx = i-k+1;
        }
        
    }
    cout<<idx;
    return 0;
}