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


struct lex_compare {
    bool cmp(pair<string,ll> a, pair<string,ll> b) {
    return a.second<b.second;
    }
};

int main(){
    fast;
    int n;
    cin>>n;
    set<pair<string,ll>, lex_compare>st;
    map<string,ll>mp;
    FOR(i,1,n) {
        ll tmp,v;
        string s;
        cin>>tmp;
        cin>>s;
        cin>>v;
        if(tmp==1) {
            st.insert({s,v});
            mp[s] = v;
        } else if(tmp==2) {
            auto it  = st.find({s,mp[s]});
            st.erase(it);
            st.insert({s,v});
            mp[s] = v;
        } else {
            cout<<st.begin()->first<<" "<<i<<endl;
            st.erase(st.begin());
        }
    }
    return 0;
}