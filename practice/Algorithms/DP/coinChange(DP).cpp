//Coin change problem(DP) 
//Time Complexity => O(n*sum)
//Space complexity => O(sum)

#include<bits/stdc++.h>
using namespace std;

int countWays(int *arr,int n,int sum){
    
    int dp[sum+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=sum;j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
    return dp[sum];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,sum;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        cin>>sum;
        cout<<countWays(arr,n,sum);
    }
return 0;
}