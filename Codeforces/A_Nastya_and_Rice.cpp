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
        int n;
        cin>>n;
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int xmin = (a-b)*n;
        int xmax = (a+b)*n;
        int ymin = c-d;
        int ymax = c+d;
        bool ans = 0;
        FOR(i,ymin,ymax) {
            if(i<=xmax and i>=xmin) {
                ans = 1;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}