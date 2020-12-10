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
vi ans;
void dfs(int cur, bool *vis, vector<int>g[]){
    vis[cur] = true;
    for(int ch: g[cur]) {
        if(!vis[ch]) {
            dfs(ch, vis, g);
        }
    }
    ans.pb(cur);
}

int32_t main(){
    fast;
    test() {
        int n,m;cin>>n>>m;
        ans.clear();
        vp edges;
        vector<int> g[n];
        for(int i=0;i<m;i++) {
            int u,v,type;
            cin>>type>>u>>v;
            --u;--v;
            if(type == 1) {
                g[u].push_back(v);
            } 
            edges.push_back({u,v});
        }
        bool vis[n];
        memset(vis, 0, sizeof vis);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i,vis,g);
            }
        }
        reverse(all(ans));
        vi pos(n);
        for(int i=0;i<n;i++) {
            pos[ans[i]] = i;       
        }
        bool bad = false;
        for(int i=0;i<n;i++) {
            for(int j: g[i]) {
                if(pos[j] < pos[i]) {
                    bad = true;
                }
            }       
        }
        if(bad) {
            cout<<"NO"<<endl;
        } else{
            cout<<"YES"<<endl;
            for(auto [x,y] : edges) {
                if(pos[x] < pos[y]) cout<<x+1<<" "<<y+1<<endl;
                else {
                    cout<<y+1<<" "<<x+1<<endl;
                }
            } 
        }
    }
    return 0;
}
