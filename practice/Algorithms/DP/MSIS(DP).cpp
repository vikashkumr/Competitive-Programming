//Maximum Sum Increasing Subsequence
//Time Complexity => O(n^2) n=length of array   
//Bottom up DP solution

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define ll long long
ll dp[MAX];
ll max(ll x, ll y){
    return (x>y)?x:y;
}
int main(){
    ios_base::sync_with_stdio(false);
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            ll *arr = new ll[n];

            //take input and initialize dp arr with same input as atleast sum of that index could be arr[i]
            for(ll i=0;i<n;i++){
                cin>>arr[i];
                dp[i]=arr[i];
            } 
            
            //update sum in dp[i] each time we find element less than arr[i] and keep max sum on that index
            for(ll i=1;i<n;i++){
                for(ll j=i-1;j>=0;j--){
                    if(arr[j]<arr[i]){
                        dp[i]=max(dp[j]+arr[i],dp[i]);
                    }
                }
            }

            //check max in dp arr 
            ll mx = -1;
            for(int i=0;i<n;i++){
                if(dp[i]>mx)
                mx=dp[i];
            }

            cout<<mx<<endl;
        }
    return 0;
}