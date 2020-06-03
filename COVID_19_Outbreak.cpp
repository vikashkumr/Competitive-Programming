//status: TLE

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
#define matrix vector<vector<int> >
#define vi vector<int>
#define vs vector<string>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};
//=================================================================//
unordered_map<int,vector<pair<int,int>>> g;
unordered_map<int,bool> vis;
void dfs(int z, int *nodeW) {
    vis[z] = 1;
    for(auto it: g[z]) {
        if(!vis[it.first]) {
            dfs(it.first,nodeW);
            nodeW[z]+=min(nodeW[it.first],it.second);
        }
    }
}

#undef int
int main(){
#define int long long 
    fast;
    int n, z;
    cin>>n>>z;
    for(int i=0;i<n-1;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int nodeW[n+1];
    for(int i=1;i<=n;i++){
        cin>>nodeW[i];
    }
    int ans = 0;
    dfs(z,nodeW);
    cout<<nodeW[z];
    return 0;
}