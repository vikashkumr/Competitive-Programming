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
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};
//=================================================================//
vector<vector<int>> g;
vector<int> goodNode; //initially not good 0
priority_queue<pair<int,int>> cnt; //initially 0
vector<bool> vis;


//to mark all node as good which are reachable from src node
void dfs(int x) {
    goodNode[x] = 1;

    for(auto child: g[x]) {
        if(!goodNode[child]) {
            dfs(child);
        }
    }
}

//to count not good node
void dfs1(int node, int &cntN) {
    vis[node] = 1;
    cntN++;
    for (auto child: g[node]) {
        if(!vis[child] && goodNode[child]==0) {
            dfs1(child,cntN);
        }
    }
}

#undef int
int main(){
#define int long long 
    fast;
    int n, m, s;
    cin >> n >> m >> s;
    g.resize(n + 1);
    goodNode.resize(n+1);
    
    for (int i = 0; i < m;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(s);
    // for (int i = 1; i <= n;i++) cout<<goodNode[i]<<" ";
        for (int i = 1; i <= n; i++)
        {
            if (!goodNode[i])
            {
                vis.clear();
                vis.resize(n + 1);
                int cntN = 0;
                dfs1(i, cntN);
                cnt.push({cntN - 1, i});
            }
        }
    int ans = 0;
    while(!cnt.empty()) {
        int topNode = cnt.top().second;
        if(goodNode[topNode]==0) {
            ans++;
            dfs(topNode);
        }
        cnt.pop();
    }
    cout << ans;
    return 0;
}