    //Given a cost matrix and a position (m, n) , Find cost of minimum cost path to reach (m, n) from (0, 0)
    //Time complexity => O(m*n)
    //Space complexity => O(m*n)
    //Bottom Up approach
    #include<bits/stdc++.h>
    #define MAX 21
    using namespace std;

    int dp[MAX][MAX]={0};

    void findCost(int cost[][MAX],int n,int m){
        dp[0][0]=cost[0][0];
        
        //Initializing top row
        for(int i=1;i<m;i++)
        dp[0][i]=cost[0][i]+dp[0][i-1];

        //Initializing leftMost column
        for(int i=1;i<n;i++)
        dp[i][0]=cost[i][0]+dp[i-1][0];

        //constructing dp(cost array)
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=cost[i][j]+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }

    int main(){
        int n,m,x,y;
        cin>>n>>m;
        int cost[21][21];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            cin>>cost[i][j];
            }
        }

        cin>>x>>y;
        findCost(cost,n,m);
        cout<<dp[x][y];
    return 0;
    }