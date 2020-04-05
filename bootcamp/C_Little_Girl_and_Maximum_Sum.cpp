#include<bits/stdc++.h>
using namespace std;
#define MAX_N 300001
#define ll long long int
ll arr[MAX_N];
ll new_arr[MAX_N];
ll BIT[MAX_N];
void update(ll i, ll inc,ll n) {
    while(i<=n) {
        BIT[i] +=inc;
        i = i + (i&(-i));
    }
}

ll query(ll i)
{
    ll sum=0;
    while (i>0)
    {
        sum+=BIT[i];
        i -= (i & -i);
    }
    return sum;
}
int main() {
    ll n,q,sum = 0;
    cin >> n >> q;
    for(ll i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    ll l,r;
    while(q--) {
        cin >> l >> r;
        update(l,1,n);
        update(r+1,-1,n);
    } 
    for (ll i=1;i<=n;i++)
    {
        new_arr[i] = query(i);
    }
    sort(new_arr+1,new_arr+n+1);
    long long ret = 0;
    for (ll i=n;i>=1;i--)
    {
        ret += arr[i] * new_arr[i];
    }
    cout << ret << endl;
    return 0;
}