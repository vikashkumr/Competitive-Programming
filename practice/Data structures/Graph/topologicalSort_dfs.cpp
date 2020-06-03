#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
    unordered_map<T, list<T> > adj;
    void tps_dfs_helper(T node, list<T> &l, unordered_map<T, bool> &vis) {
        vis[node] = true;
        for(auto child: adj[node]) {
            if(!vis[child]) {
                tps_dfs_helper(child, l, vis);
            }
        }
        l.push_front(node);
    }

public:
    void addEdge(T u, T v, bool bidir = false) {
        adj[u].push_back(v);
        if(bidir) adj[v].push_back(u);
    }

    void tps_dfs() {
        unordered_map<T, bool> vis;
        list<T> l;
        for(auto node: adj) {
            if(!vis[node.first]) {
                tps_dfs_helper(node.first, l, vis);
            }
        }
        for(auto node: l) cout << node <<" ";
    }
};

int main(){

    int n;
    cin >> n;
    Graph<string> g;
    string u, v;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.tps_dfs();
    return 0;
}