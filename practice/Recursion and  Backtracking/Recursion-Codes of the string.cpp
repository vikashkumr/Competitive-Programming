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
string mp = "@abcdefghijklmnopqrstuvwxyz";
vector<string>v;
void solve(string s, int i,int j,string res) {
    //base case
    if(i==j) {
        v.push_back(res);
        return;
    }
    
    //recursive case
    solve(s,i+1,j,res+mp[s[i]-'0']);
    if(i<=s.length()-2) {
    	int dig2 = (s[i]-'0')*10+(s[i+1]-'0');
	    if(dig2<=26) {
	        solve(s,i+2,j,res+mp[dig2]);
	    }	
    }
}

int main(){
    fast;
    string s;
    cin>>s;
    cout<<"[";
    solve(s,0,s.length(), ""); 
    for(string st: v) {
    	if(v[v.size()-1]==st)
    	cout<<st;
    	else cout<<st<<", ";
    }
    cout<<"]";
    return 0;
}