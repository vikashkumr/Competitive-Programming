bool cycle(vector<int> g[], int V, int cur, bool *vis) {
    vector<int>parent(V+1, -1);
    queue<int> q;
    vis[cur] = true;
    q.push(cur);
    while(!q.empty()) {
        int node = q.front();q.pop();
        for(int child: g[node]) {
            if(!vis[child]) {
                parent[child] = node;
                vis[child] = true;
                q.push(child);
            } else { // checking if child is not parent if it is parent skip else cycle found
                if(parent[node] != child) return true;
            }
        }
    }
    return false;
}


bool isCyclic(vector<int> g[], int V)
{
   bool vis[V+1]{0};
   for(int i=0;i<V;i++) {
       if(!vis[i] and cycle(g, V, i, vis)) {
           return true;
       }
   }
   return false;
   
}