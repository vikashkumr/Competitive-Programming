//g++  5.4.0

//coins change problem

#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int vis[N][N],dp[N][N];
int ways(int *coins, int pos, int sum){

    if(pos==n) return sum==0;
    if(vis[pos][sum])
    return dp[pos][sum];

    vis[pos][sum]=1;
    int &ans=dp[pos][sum],times=0;

    while(times*coins[pos]<=sum){
        ans+=ways(coins,pos+1,sum-times*coins[pos]);
        times++;
    }

    return ans;
}


int fasterWays(int *coins, int pos, int sum){

    if(pos==n) return sum==0;
    if(sum<0) return 0;
    int &ans=dp[pos][sum];

    if(vis[pos][sum])
    return ans;

    vis[pos][sum]=1;

    ans=fasterWays(coins,pos,sum-coins[pos])+fasterWays(coins,pos+1,sum);

    return ans;
}


int main()
{
    int sum;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++) cin>>coins[i];
    cin>>sum;
    cout<<fasterWays(coins,0,sum)<<endl; 
    return 0;
}