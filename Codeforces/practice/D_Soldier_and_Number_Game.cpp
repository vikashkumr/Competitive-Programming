#include<bits/stdc++.h>	
using namespace std;
#define test()  int t;cin>>t;while(t--)
#define  _IO    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define MAX  5000001
#define ll long long
ll noOfFactor[MAX];
int dp[MAX];
//factorization

void factors() {
    //sieve
    for(int i=2;i*i<MAX;i++) {
        if(dp[i]==0) {
            for(int j = i*i;j<MAX;j+=i) {
              dp[j] = i;  
            }
        }
    }

    for(int i=1;i<MAX;i++) {
        if(dp[i]==0) {
            noOfFactor[i]++;
        } else {
            //loved this hack
            noOfFactor[i] = noOfFactor[i/dp[i]]+1;
        }
    }
    //prefix array
    for(int i=1;i<MAX;i++) noOfFactor[i]+=noOfFactor[i-1];
}


int main() {
    _IO
    factors();
    test() {

        int a, b;
        cin>>a>>b;
        cout<<noOfFactor[a]-noOfFactor[b]<<"\n";
        
    }
    return 0;
}