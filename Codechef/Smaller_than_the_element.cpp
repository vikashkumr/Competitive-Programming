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
    set<ll>st;
    ll n;
    cin>>n;
    ll temp;
    while(n--) {
        cin>>temp;
        st.insert(temp);
        auto it = st.lower_bound(temp);
        if(it==st.begin()) cout<<-1<<endl;
        else {
            it--;
            cout<<*it<<endl;
        } 
    }
    return 0;
}
