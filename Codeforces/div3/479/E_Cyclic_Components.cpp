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
#define pii pair<int,int>
#define vs vector<string>
#define vp vector<pii>
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int sz = 100005;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//
vector<bool> vis;
bool dfs(vector<int> g[], int cur, int *indegree) {
    vis[cur]=1;
    if(indegree[cur]!=2) return false;
    bool ans = true;
    for(int child: g[cur]) {
        if(!vis[child]) {
            ans&=dfs(g, child, indegree);
        }
    }
    return ans;
}


int32_t main(){
    fast;
    int n, m;
    cin>>n>>m;
    vector<int>g[n+1];
    vis.resize(n+1);
    int indegree[n+1]={0};
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
        indegree[u]++; indegree[v]++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            ans += dfs(g, i, indegree);
        }
    }
    cout<<ans<<endl;
    return 0;
}