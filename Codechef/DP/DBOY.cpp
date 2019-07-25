#include<bits/stdc++.h>
using namespace std;
void minTime(int kArray[], int dp[], int maxDis,int n){
    for(int i=0;i<=maxDis;i++){
        dp[i] = INT_MAX;
    }
    dp[0]=0;
    for(int ithValueK=1;ithValueK<=maxDis;ithValueK++){
        for(int i=0;i<n;i++){
            if(ithValueK-kArray[i]>=0){
                int smallAns = dp[ithValueK-kArray[i]];
                if(smallAns!=INT_MAX){
                    dp[ithValueK] = min(dp[ithValueK],1+smallAns);
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,ans=0,mx=0;
        cin>>n;
        int *H = new int[n];
        int *k = new int[n];
        for(int i=0;i<n;i++){
            cin>>H[i];
            H[i]=2*H[i];
            if(H[i]>mx)
            mx=H[i];
        }
        int dp[mx+1];
        for(int i=0;i<n;i++){
            cin>>k[i];
        }
        minTime(k,dp,mx,n);
        for(int i=0;i<n;i++){
            ans+=dp[H[i]];
        }
        cout<<ans<<"\n";
    }
    return 0;
}