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
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//
ll cnt = 0;
void solve(ll i, ll j, ll n, ll m) {
    
    //corner case
    if(i<1 || j<1 || i>n || j>m) {
        return;
    }

    //base case
    if(i==n && j==m) {
        cnt++;
        return;
    }

    //recursive case
    solve(i+1,j,n,m);
    solve(i,j+1,n,m);
    solve(i+1,j+1,n,m);
}


int main(){
    fast;
    ll n,m;
    solve(1,1,n,m);
    cout<<cnt;
    return 0;
}