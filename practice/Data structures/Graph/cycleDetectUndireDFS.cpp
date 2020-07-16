#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
    unordered_map<T, list<T> > adj;
    bool isCyclic_dfs_helper(T node, unordered_map<T, bool> & vis, T parent) {
        vis[node] = true;
        for(auto child: adj[node]) {
            if(!vis[child]) {
                bool isCycle = isCyclic_dfs_helper(child, vis, node);
                if(isCycle) return true;
            } else if(child != parent) {
                return true;
            }
        }
        return false;
    }

public:
    void addEdge(T u, T v, bool bidir = true) {
        adj[u].push_back(v);
        if(bidir) adj[v].push_back(u);
    }

    bool isCyclic_dfs() {
        unordered_map<T, bool> vis;
        for(auto it: adj) {
            T node = it.first;
            if(!vis[node]) {
                bool isCycle = isCyclic_dfs_helper(node, vis, node);
                if(isCycle) return true;
            }
        }
        return false;
    }

    bool isCyclic_bfs(T src) {
        unordered_map<T, bool> vis;
        unordered_map<T, T> parent;
        parent[src] = src;
        vis[src] = true;
        queue<T>q;
        q.push(src);
        while(!q.empty()) {
            T node = q.front();
            q.pop();
            for(auto child: adj[node]) {
                if((vis[child]==true) && (parent[node] != child)) {
                    return true;
                } else if(!vis[child]){
                    vis[child] = true;
                    parent[child] = node;
                    q.push(child);
                }
            }
        }
        return false;
    }
};

int main(){

    int n;
    cin >> n;
    Graph<int> g;
    int u, v;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << g.isCyclic_dfs();
    cout << g.isCyclic_bfs(1);
    return 0;
}

/*INPUT

6
1 2
1 4
2 3
3 5
5 6
5 7

*/