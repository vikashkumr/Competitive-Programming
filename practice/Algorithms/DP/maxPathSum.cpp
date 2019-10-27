//g++  5.4.0

//maximum path sum in 2d grid from (0,0) to (n-1,m-1)

#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int n,m,a[N][N],dp[N][N],vis[N][N];

int solve(int i,int j){
    if(i==n-1 && j==m-1)
        return a[i][j];
    
    if(vis[i][j])
        return dp[i][j];
    vis[i][j]=1;
    int &ans = dp[i][j]; //taking reference
    if(i<n-1 && j<m-1)
    ans = a[i][j]+max(solve(i,j+1),solve(i+1,j));
    else if(i==n-1)
       ans = a[i][j]+solve(i,j+1);
    else if(j==m-1)
       ans = a[i][j]+solve(i+1,j);
    return ans;
}


int main()
{
   cin>> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>> a[i][j];
        
        //display matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cout<< a[i][j]<<" ";
        cout<<"\n";
    }
    
    cout<<solve(0,0)<<endl;
    
    return 0;
}