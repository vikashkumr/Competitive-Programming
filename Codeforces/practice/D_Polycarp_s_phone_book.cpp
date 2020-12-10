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
map<string,int>mp;

void storeSubs(string s, int n) {
    int l = s.length();
    string temp;
    for(int i=0;i<l;i++) {
        for(int j=i;j<l;j++) {
            temp = s.substr(i,j-i+1);
            if(mp[temp]==0) {
                mp[temp] = n;
            } else if(mp[temp]!=n){
                mp[temp] = -1;
            }
        }
    }
}

#undef int
int main(){
#define int long long 
    fast;
    int n;
    string s;
    cin>>n;
    FOR(i,1,n) {
        cin>>s;
        storeSubs(s,i);
    }
    vector<pair<int,string> >vp;
    for(auto it : mp) {
        if(it.second != -1) {
            vp.push_back({it.second,it.first});
        }
    }
    sort(all(vp),[&](pair<int,string>a , pair<int,string> b) -> bool{
    if(a.first==b.first) {
        return a.second.length()<b.second.length();
    }
    return a.first<b.first;
    });
    int cnt = 1;
    for(auto it : vp) {
        if(it.first==cnt) {
            cout<< it.second<<endl;
            cnt++;
        }
    }
    return 0;
}