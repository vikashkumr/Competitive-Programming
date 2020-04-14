#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,m,mid;
    cin>>n>>m;
    if(n<=m){
        cout<<n;
        exit(0);
    }
    ll l = 0, r = 10000000000;
    n = n-m;
    while(l<r) {
        ll mid = (l+r)/2;
        ll temp = ((mid)*(mid+1))/2;
        if(temp>=n) {
            r=mid;
        } else {
            l = mid+1;
        }
    }
    cout<<l+m;
    return 0;
}