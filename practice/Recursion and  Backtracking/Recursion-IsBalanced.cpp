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
bool check(string s, int i, string res) {
   // cout<<res<<endl;
    if(i==(int)s.length()) {
        return res.length()==0;
    }
    if(s[i]=='(' or s[i]=='{' or s[i]=='[') {
        res = res+s[i];
        return check(s,i+1,res);
    } if(s[i]==')' and res[res.length()-1]=='(') {
        res.pop_back();
        return check(s,i+1,res);
    } if(s[i]=='}' and res[res.length()-1]=='{') {
        res.pop_back();
        return check(s,i+1,res);
    } if(s[i]==']' and res[res.length()-1]=='[') {
        res.pop_back();
        return check(s,i+1,res);
    }
    return false;
}


int main(){
    fast;
    string s,res = "";
    cin>>s;
    for(char ch : s) {
        if(ch=='[' or ch=='{' or ch=='(' or ch==')' or ch=='}' or ch==']')
        res+=ch;
    }
   // cout<<res<<endl;
    if(check(res,0, ""))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}