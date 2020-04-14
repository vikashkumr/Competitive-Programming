#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 100;
int t[MAX_N], l[MAX_N], h[MAX_N];
bool isller(ll x, ll y, ll l, ll h) {
    if(x<=h and l<=y) return true;
    return false;
}
int main() {
    ll q;
    cin>>q;
    while(q--) {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++) 
         cin>>t[i]>>l[i]>>h[i];
        int prev = 0;
        int mn = m, mx = m;
        bool flag = 1;
        for(int i=0;i<n;i++) {
            mn -= t[i]-prev;
            mx += t[i]-prev;
            if(isller(mn,mx,l[i],h[i])) {
                mx = min(mx,h[i]);
                mn = max(mn,l[i]);
            } else {
                //cout<<"NO\n";
                flag = !flag;
                break;
            }
            prev = t[i];
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}