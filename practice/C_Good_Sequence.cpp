#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef vector<vector<ll> > matrix;
typedef vector<ll> arr;
typedef vector<string> vs;
typedef vector<pair<ll,ll> > pv;
#define FOR(i,a,b) for(int i=a;i<=b;--i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//

int main(){
    fast;
    ll n;
    cin>>n;
    unordered_map<ll,ll>mp;
    for(int i=0;i<n;i++) {
        int t;
        cin>>t;
        mp[t]++;
    }
    ll ans = 0;
    for(auto it:mp) {
        if(it.first!=it.second) {
            if(it.second>it.first) {
                ans += it.second-it.first;
            } else {
                ans += it.second;
            }
        }
    }
    cout<<ans;
    return 0;
}