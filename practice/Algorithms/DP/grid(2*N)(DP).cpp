//You have a rectangular grid of dimension 2 x n. You need to find out the maximum sum such that no two chosen numbers are adjacent , vertically, diagonally (or) horizontally.

//Time Complexity O(n)
//Space complexity O(n) dp[n] // can be reduced to O(1) because ans is depending on last two index of dp
//Bottom up Dp 

#include<iostream>
using namespace std;
int main()
 {
    int n;
    cin>>n;
    int arr[2][n];
    
    //input
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }

    //building dp table dp[n] keep track of max sum till i
    int dp[n];
    dp[0]=max(arr[0][0],arr[1][0]);
    dp[1]=max(max(arr[0][1],arr[1][1]),dp[0]);
	    for(int j=2;j<n;j++){
	        dp[j]=max(dp[j-1],dp[j-2]+max(arr[0][j],arr[1][j]));
	    }

        int mxsum = -1;
	for(int i=0;i<n;i++){
        if(dp[i]>mxsum)
        mxsum = dp[i];
    }
    cout<<mxsum<<endl;
	return 0;
}