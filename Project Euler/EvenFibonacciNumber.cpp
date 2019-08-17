//Even Fibonacci number
//project euler
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll first,second,ans,sum = 0;
    first = 1;
    second =2;
    ans = first + second;
    while(ans<=55){
        if((ans&1)==0)
        sum+=ans;
        ans = first+second;
        first = second;
        second = ans;
    }
    cout<<sum+2<<endl;
    return 0;
}