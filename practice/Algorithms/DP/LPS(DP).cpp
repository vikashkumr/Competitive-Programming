//Longest Pallindromic Subsequence
//Time Complexity => O(n^2) n=length of string
//Bottom up solution
//complete Search will tak O(2^n) time as it will generate all subsequence and check for pallindrome

#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
int dp[MAX][MAX];
int longestPalli(string s,int n){
    
    for(int i=0;i<=n;i++)
    dp[i][i]=1;
    
    for(int len=2;len<=n+1;len++){
        for(int i=0;i<=n;i++){
            int j = i+len-1;
            if(s[i]==s[j])
            dp[i][j]=2+dp[i+1][j-1];
            else
            dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    
    return dp[0][n];
}

int main(){
    ios_base::sync_with_stdio(false);
        string s="ABABCCBA";
        memset(dp,0,sizeof(dp));
        cout<<longestPalli(s,s.length()-1)<<"\n";
    return 0;
}