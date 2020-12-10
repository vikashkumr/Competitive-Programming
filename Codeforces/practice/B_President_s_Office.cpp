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
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//
string box[101];
map<char,bool> mp;
int n,m;

int lookaround(int i,int j) {
    int res = 0;
    //left
    if(j>0) {
        if(mp[box[i][j-1]]==0) {
            mp[box[i][j-1]] = 1;
            res++;
        }
    }
    //right
    if(j<m-1) {
        if(mp[box[i][j+1]]==0) {
            mp[box[i][j+1]] = 1;
            res++;
        }
    }
    //up
    if(i>0) {
        if(mp[box[i-1][j]]==0) {
            mp[box[i-1][j]] = 1;
            res++;
        }
    }
    //down
    if(i<n-1) {
        if(mp[box[i+1][j]]==0) {
            mp[box[i+1][j]] = 1;
            res++;
        }
    }

    return res;
}

int main(){
    fast;
    char c;
    cin>>n>>m>>c;
    for(int i=0;i<n;i++) {
        cin>>box[i];
    }
    int cnt = 0;
    mp['.'] = 1;
    mp[c] = 1;
    FOR(i,0,n-1) {
        FOR(j,0,m-1) {
        	if(box[i][j]==c)
            cnt+=lookaround(i,j);
        }
    }
    cout<<cnt;
    return 0;
}