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
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//=================================================================//
const int N = 100005;

vector<int> gr[N], revgr[N];
vector<int> order;
int comp[N];
int vis[N];

void dfs(int curr) {
    vis[curr] = 1;
    for(auto child: gr[curr]) {
        if(!vis[child]) {
            dfs(child);
        }
    }

    order.push_back(curr);
}

void dfs_reverse(int curr, int com_no) {
    comp[curr] = com_no;
    vis[curr] = 1;
    for(auto child: revgr[curr]) {
        if(!vis[child]) {
            dfs_reverse(child, com_no);
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        revgr[v].push_back(u);
    }

    for (int i = 1; i <= n;i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    memset(vis, 0, sizeof vis);
    int com_no = 0;
    for (int i = n; i >= 1; i--) {
        if(!vis[order[i]]) {
            dfs_reverse(order[i], com_no++);
        }
    }

    //printing

    for (int i = 1; i <= n; i++) {
        cout<<i<<" "<<comp[i]<<endl;
    }
}

int32_t main(){
    fast;
    solve();

    return 0;
}

/*INPUT  

6 7             
1 2
2 3
3 1
3 4
4 5
5 6
6 4

OUTPUT

1 1 \
2 1  \  In 1st component
3 1  /
4 2 \
5 2  \ In 2nd Component
6 2  /
*/