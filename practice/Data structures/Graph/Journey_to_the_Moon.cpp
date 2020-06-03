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

unordered_map<int, vector<int>> adj;
int n,p;

void dfs(int node, unordered_map<int,bool> &vis, int &ans) {
    vis[node] = 1;
    ans++;
    for(auto child: adj[node]) {
        if(!vis[child]) {
            dfs(child, vis,ans);
        }
    }
}


void journeyToTheMoon() {
    int total = n*(n-1)/2;
    int ans = 0;
    unordered_map<int, bool> vis;
    for(auto it: adj) {
        if(!vis[it.first]) {
            ans = 0;
            dfs(it.first,vis,ans);
            total-=ans*(ans-1)/2;
        }
    }
    cout<<total;
}


#undef int
int main(){
#define int long long 
    fast;
    cin>>n>>p;
    FOR(i,0,p-1) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    journeyToTheMoon();
    return 0;
}