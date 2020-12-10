#include<bits/stdc++.h>
using namespace std;
#define For(i,l,r)   for(ll i=l;i<=r;i++)
#define ll long long
#define endl "\n"
int main() {
	ll n;
    cin>>n;
    ll *t1 = new ll[n+1];
    ll *t2 = new ll [n+1];
    For(i,1,n) {
        cin >> t1[i];
        t2[i] = t1[i]; 
    }

    sort(t2+1,t2+n+1);
    For(i,2,n) {
        t1[i] += t1[i-1];
        t2[i] += t2[i-1];
    }
    t1[0] = t2[0] = 0;
    ll m;
    cin >> m;
    while(m--) {
        ll t,l,r;
        cin >> t >> l >> r;
        if(t==1) {
            cout<<t1[r]-t1[l-1]<<endl;
        } else {
            cout<<t2[r]-t2[l-1]<<endl;
        }
    }

	return 0;
}