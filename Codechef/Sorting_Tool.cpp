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

vector<int>occur; 
vector<pair<int,int>>v;
map<int,int>hsh;
map<int,int>mp;

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    
    arr v;
    map<int,int> fre,ind;
    int t;
    for(int i=0;i<n;i++) {
        cin>>t;
        if(fre[t]==0) {
            ind[t] = i;
            fre[t]++;
        } else {
            fre[t]++;
        }
        v.pb(t);
    }

    sort(all(v),[&](ll a, ll b) -> bool {
        if(fre[a]>fre[b]) return true;
        else if(fre[b]>fre[a]) return false;
        else if(ind[a]<ind[b]) return true;
        else return false;
    });
    for(int it : v) cout<<it<<" ";

    return 0;
}