#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll countleft(ll i,ll *arr) {
    ll cnt = 0;
    i--;
    while(i>=0) {
        if(arr[i]&1) {
            cnt++;
            i--;
        } else break;
    }
    return cnt;
}
ll countright(ll i,ll *arr,ll n) {
    ll cnt = 0;
    i++;
    while(i<n) {
        if(arr[i]&1) {
            cnt++;
            i++;
        } else break;
    }
    return cnt;
}


int main() {

    ll t;
    cin>>t;
    while(t--) {
        ll  n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            //arr[i] = abs(arr[i]);
            if(arr[i]<0) arr[i]=-1*arr[i];
            arr[i]%=4;
        }
        

        ll sum = 0;
        for(ll i=0;i<n;i++) {
            if(arr[i]==2) {
                ll l = countleft(i,arr);
                ll r = countright(i,arr,n);
                sum += l+r+(l*r)+1;
            }
        }
        ll temp = (n*(n+1))/2;
         cout<<temp - sum<<"\n";
    }
    return 0;
}