#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll *arr = new ll[n];
        ll *dp = new ll[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        dp[n-1]=1;
        for(ll i=n-2;i>=0;i--){
            if((arr[i]*arr[i+1])<0){
                dp[i]=1+dp[i+1];
            }
            else {
                dp[i]=1;
            }
        }
        for(ll i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}