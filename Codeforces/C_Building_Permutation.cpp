#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll absl(ll a) {
    if(a<0) return -a;
    return a;
}
int main()  {
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll ans = 0;
    for(ll i=1;i<=n;i++) {
        ans += absl(i-arr[i-1]);
    }
    cout<<ans;
    return 0;
}