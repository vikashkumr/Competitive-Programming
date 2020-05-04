#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
typedef long double ld;
typedef vector<vector<int> > matrix;
typedef vector<int> arr;
typedef vector<string> vs;
typedef vector<pair<int,int> > pv;
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//
int f[50];
 int x, k;
void solve(int x1, int z, int k1) {
    if(z<1) return;
    if(1 * (k-k1) *f[z]<x) return;
    if(x1==0)
}

#undef int
int main(){
#define int long long 
    fast;
    int q;
    cin>>q;
    while(q--) {
       
        cin>>x>>k;
        int ans = 0;
        f[1] = 1;
        f[2] = 2;
        for(int i=3;i<=43;i++) f[i] = f[i-1] + f[i-2];
        solve(x,43,0);
        cout<<ans<<endl;

    }
    
    return 0;
}