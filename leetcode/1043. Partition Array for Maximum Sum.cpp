#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        int dp[n];
        for(int i=0;i<n;i++) dp[i] = 0;
        dp[0] = A[0];
        
        //preprocess k elements
        int mx = dp[0];
        for(int i=1;i<K;i++) {
            mx = max(mx,A[i]);
            dp[i] = max(mx,A[i])*(i+1);
        }

        for(int i=K;i<n;i++) {
            int curr_ele = A[i];
            mx = A[i];
            for(int k=1;k<=K;k++) {
                mx = max(mx,A[i-k+1]);
                dp[i] = max(dp[i-k]+mx*k,dp[i]);
            }
        }
       // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return dp[n-1];
    }
};