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
bool check(string s, int idx) {
    if(idx==s.length()) {
       return true;
    }
    if(s[idx]=='a') {
        check(s,idx+1);
    } else if(idx <= s.length()-2 and s[idx]=='b' and s[idx+1]=='b'){
        check(s,idx+2);
    } else 
        return false;
}


int main(){
    fast;
    string s;
    cin>>s;
    if(check(s,0))
        cout<<"true";
    else 
        cout<<"false";
    
    return 0;
}