===========================================DFS=======================================================================

{
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);
        
        cout<<endl;
    }
}
}
void dfs(int s, vector<int> g[], bool vis[])
{
{
 vis[s]=true;
 cout<<s<<" ";
 for(auto it=g[s].begin();it!=g[s].end();it++){
     if(vis[*it]==0)
     dfs(*it,g,vis);
 }
}



=============================================================BFS==========================================================


{
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N];
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis);
        cout<<endl;
    }
}

}
void bfs(int s, vector<int> adj[], bool vis[])
{
    queue<int>q;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        cout<<s<<" ";
        for(auto it=adj[s].begin();it!=adj[s].end();it++){
            if(vis[*it]==0){
                vis[*it]=true;
                q.push(*it);
            }
            
        }
        q.pop();
    }
    
}
