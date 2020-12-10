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


#undef int
int main(){
#define int long long 
    fast;
    test() {
        int n,m,k;
        cin>>n>>m>>k;
        int h[n];
        FOR(i,0,n-1) cin>>h[i];
        bool ok = 0;
        FOR(i,0,n-2) {
            m+=(h[i]-max(0LL,h[i+1]-k));
            if(m<0) ok = 1;
        }
        if(ok) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
    return 0;
}
