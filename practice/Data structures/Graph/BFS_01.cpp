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
unordered_map<int, list<pair<int,int>>> g;// {src, {dest, weight}}
void BFS_0_1(int src) {

    unordered_map<int, int> dist;//initially distance of all node from source is infinite
    for(auto node: g) {
        dist[node.first] = INT_MAX;
    }

    deque<int> q;//push node
    q.push_back(src);

    dist[src] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop_front();
        for(auto child: g[node]) {
            if (dist[child.first] == INT_MAX) {
                int edge_dist = child.second;
                dist[child.first] = dist[node] + edge_dist;
                if (edge_dist) {
                    q.push_back(child.first);
                } else {
                    q.push_front(child.first);
                }
            }
        }
    }

    //printing
    for (auto node : g) {
        cout << "Distance of " << node.first << " from " << src << " is " << dist[node.first] << endl;
    }
}

#undef int
int main(){
#define int long long 
    fast;
    int e;
    cin >> e;
    for (int i = 0; i < e;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    BFS_0_1(0);
    return 0;
}