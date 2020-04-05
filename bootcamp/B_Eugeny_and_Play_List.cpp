#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m, x, y, t;
    cin>>n>>m;
    ll arr[n];
    cin>>x>>y;
    arr[0] = x*y;
    for(ll i=1;i<n;i++) {
        cin>>x>>y;
        arr[i] = arr[i-1] + x*y;
    }
    for(ll i=0;i<m;i++) {
        cin>>t;
        ll tempIdx = upper_bound(arr,arr+n,t)-arr;
        if(arr[tempIdx-1]==t) {
            cout<<tempIdx<<"\n";
        } else {
            cout<<tempIdx+1<<"\n";
        }
    }
    return 0;
}