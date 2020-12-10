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

int main(){
    fast;
    ll n, x, ele, ans = 0,last_remove = 0;
    cin>>n;
    string s, type;
    deque<int>dq;
    n = 2*n;
    while(n--) {
        cin>>type;
        if(type == "add") {
            cin>>ele;
            dq.push_front(ele);
        } else {
            if(dq.empty()){
                last_remove++;
            }
            else if(dq.front()-last_remove>1) {
                dq.clear();
                last_remove++;
                ans++;
            } else {
                last_remove++;
                dq.pop_front();
               // dq.clear();
            }
        }
    }
    cout<<ans;
    return 0;
}