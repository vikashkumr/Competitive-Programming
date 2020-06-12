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
vector<vector<int>> edges;

vector<int> bellman_ford(int n, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, INT_MAX); //src to i
    dist[src] = 0;

    //relax every edge (n-1) times //==> nth relaxation tells about negative weight cycle
    for (int i = 1; i <= n;i++) {
        for(auto edge: edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            if (dist[to] > dist[from] + weight) {
                //checking of nth relaxation if it contains negative weight cycle
                if(i==n) {
                    cout << "Negative weight cycle present" << endl;
                    exit(0);
                }

                 //relaxed the edge
                dist[to] = dist[from] + weight;
            }
        }
    }

    return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> dist = bellman_ford(n, 1, edges);
    
    //printing
    for (int i = 1; i <= n;i++) {
        cout << "dist from src to " << i << " is " << dist[i] << endl;
    }
}

int32_t main(){
    fast;
    solve();

    return 0;
}


/* INPUT

3 3
1 2 4
1 3 5
3 2 -7

OUTPUT

dist from src to 1 is 0
dist from src to 2 is -2
dist from src to 3 is 5

*/