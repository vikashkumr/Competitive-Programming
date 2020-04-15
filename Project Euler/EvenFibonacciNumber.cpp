//Even Fibonacci number
//project euler
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
    ll first,second,ans,sum = 0;
    ll N;
    cin>>N;
    first = 1;
    second =2;
    ans = first + second;
    while(ans<=N){
        if((ans&1)==0)
        sum+=ans;
        ans = first+second;
        first = second;
        second = ans;
    }
    cout<<sum+2<<endl;
    } 
    return 0;
}