//calculate nCr
//dp solution
//C(n,r) = C(n-1,r)+C(n-1,r-1)
//print ans%10^9+7


#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define Mod 1000000007
#define test() int t;cin>>t;while(t--)
long long dp[1001][1001];

long long c(long long n, long long r){
    
    
    //base case
    if(n<r)
    return dp[n][r] = 0;
    if(r==0 || r==n || n==0)
    return dp[n][r] = 1;
    
    //check if ans is already calculated
    if(dp[n][r]!=0)
    return dp[n][r];
    
    
    //recursive case
    return dp[n][r] = (c(n-1,r-1)%Mod+c(n-1,r)%Mod)%Mod;
}

int main(){
	test(){
		long long n,r;
        cin>>n>>r;
        memset(dp,0,sizeof(dp));
        cout<<c(n,r)%Mod<<endl;

	}
}