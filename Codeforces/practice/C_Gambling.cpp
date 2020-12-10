#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()  {
    ll n;
    cin>>n;
    ll A[2*n+2]={0};
    for(ll i=0;i<n;i++) cin>>A[i];
    ll B[2*n+2]={0};
    for(ll i=0;i<n;i++) cin>>B[i];
    sort(A,A+n);
    sort(B,B+n);
    reverse(A,A+n);
    reverse(B,B+n);
    bool flag = 1;
    ll a = 0,b=0;
    ll i=0,j=0,moves = 0;
    while(moves<2*n) {
        moves++;
        if(flag) {
            if(A[i]>=B[j]) a+=A[i++];
            else
            j++;
            flag = 0;
        }
        else {
            if(B[j]>=A[i]) b+=B[j++];
            else
            i++;
            flag = 1;
        }
    }
    std::cout<<a-b;
    return 0;
}