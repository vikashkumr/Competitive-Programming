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
        int x,y;
        cin>>x>>y;
        int a,b;
        cin>>a>>b;
        int ans = 0;
        if(x==0){
            cout<<a*y<<endl;
            continue;
        }
        if(y==0) {
            cout<<a*x<<endl;
            continue;
        }

        if(x==y) {
            cout<<min(x*b,x*a*2)<<endl;
            continue;
        }
        if(x<y) {
            int ans = min(x*b+(y-x)*a, min((x*a)+(y*a),(y-x)*a+2*a*x));
            cout<<ans<<endl;

            //cout<<x*b+(y-x)*a<<endl;
            continue;
        }
        if(x>y) {
            int ans = min(y*b+(x-y)*a, min((y*a)+(x*a),(x-y)*a+2*a*y));
            cout<<ans<<endl;

            //cout<<x*b+(y-x)*a<<endl;
            continue;
        }
    }
    return 0;
}