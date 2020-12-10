#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
    unordered_map<T, list<T> > adj;
    bool isCyclic_dfs_helper(T node, unordered_map<T, bool> & vis, unordered_map<T, bool> & instack) {
        instack[node] = vis[node] = true;

        for(auto child: adj[node]) {
            //instack check is if that node is in current path of dfs (then there will be cycle)
            if((!vis[child] and isCyclic_dfs_helper(child, vis, instack)) or instack[child]) {
                return true;
            }
        }
        instack[node] = false; // removing from current path after completely explored
        return false;
    }

public:
    void addEdge(T u, T v, bool bidir = false) {
        adj[u].push_back(v);
        if(bidir) adj[v].push_back(u);
    }

    bool isCyclic_dfs() {
        unordered_map<T, bool> vis, instack;
        for(auto it: adj) {
            T node = it.first;
            if(!vis[node]) {
                bool isCycle = isCyclic_dfs_helper(node, vis, instack);
                if(isCycle) return true;
            }
        }
        return false;
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
    cout<<g.isCyclic_dfs();
    return 0;
}