#include<bits/stdc++.h>
#define ll long long
#define MAX 100001
using namespace std;
ll dp[MAX]={0};

ll go(ll arr[], ll i, ll n){
    if(dp[i])
    return dp[i];
    if(i==n)
    return dp[i]=i*arr[i];
    if(i==n-1){
        ll temp1 = (i*arr[i])+(i+1)*arr[i+1];
        ll temp2 = (i*arr[i+1]) + (i+1)*arr[i];
        return  dp[i] = max(temp1,temp2);
    }
    return dp[i] = max((i*arr[i]+go(arr,i+1,n)), 
    max((i*arr[i])+(i+1)*arr[i+1],
    (i*arr[i+1]) + (i+1)*arr[i]) + go(arr,i+2,n));
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n+1];
        for(ll i=1;i<=n;i++){
            cin>>arr[i];
        }
        cout<<go(arr,1,n)<<"\n";
        // cout<<sum<<"\n";
        for(ll i=0;i<=n;i++)
        dp[i]=0;
    }
    return 0;
}