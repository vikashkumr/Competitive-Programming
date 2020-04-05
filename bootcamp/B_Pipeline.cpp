#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sum(ll k) {
    return ((ll) (k+2)*(k-1))/2;
}
ll search(ll n, ll k) {
    ll l = 2;
    ll r = k;
    ll prevl = 2;
    ll ans = -1;
    if((sum(r)-sum(l-1)-r+l)<n) return -1;
    if((sum(r)-sum(l-1)-r+l)==n) return r-l+1;
    while(l<=r) {
        ll mid = (l+r)/2;
        if((sum(r)-sum(l-1)-r+l)==n) {
            return r-l+1;
        }
        else if((sum(r)-sum(l-1)-r+l)>n){
            ans = r-l+1;
            prevl = l;
            l = mid+1;
        } else {
            l = (prevl+l)/2;
            if(l==prevl) return ans;
        }
    }
    return ans;
}

int main() {
    ll n,k;
    cin >> n >> k;
    if(n==1) cout<<0<<"\n";
    else
    cout<<search(n,k)<<"\n";
    return 0;
}