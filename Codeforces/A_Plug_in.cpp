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
    string s,res="";
    cin>>s;
    for(int i=0;i<s.length();i++) {
        if(s[i]==s[i+1]) {
            i++;
        } else {
            if(res.length()==0) res.push_back(s[i]);
            else if(res[res.length()-1]!=s[i]) res.push_back(s[i]);
            else res.pop_back();
        }
    }
    cout<<res;
    return 0;
}