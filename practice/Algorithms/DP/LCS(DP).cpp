//Longest common subsequence (DP)
//Given two sequences, find the length of longest sub sequence present in both of them.
//Time complexity => O(n*m) //n=length of first sequence m=length of second sequence 
//Space complexity => O(n*m) //Bottom up approach

#include<bits/stdc++.h>
#define MAX 102
using namespace std;

int dp[MAX][MAX];

void LCS(string str1,string str2){
    memset(dp,0,sizeof(dp));
    int len1 = str1.length();
    int len2 = str2.length();
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}
int main(){
    string str1="AABC",str2="ABC";
    LCS(str1,str2);
    int ans = dp[str1.length()][str2.length()];
    cout<<ans<<endl;
   return 0;
}
