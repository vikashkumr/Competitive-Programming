//Dijkstra Algorithm O(ElogV) (E = Edge, V = vertex)
//implemented using adjecency List undirected Graph 
//Can be easily converted to directed Graph (chage addEdge function) 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INT_MAX 100000000000000000LL
//adjecency list for udirected graph
void addEdge(vector<pair<ll,ll> >adj[], ll u, ll v, ll value){
   adj[u].push_back(make_pair(v,value));
//    adj[v].push_back(make_pair(u,value));
}

int main() {
   ll V,m;
   cin>>V>>m;
   ll u,v,value;
   vector<pair<ll,ll> >adj[V]; //adjecency list contain a-->b pair<b,weight(a-->b)>
    for(ll i=0;i<m;i++) {
        cin>>u>>v>>value;
        addEdge(adj,u-1,v-1,value);
    }
   bool visited[V]; // visited array to not compute same vertex again
   memset(visited,false,sizeof(visited));
   ll distance[V];  //record of path length from sourse to i'th vertex

   //innitialise
   distance[0]=0; 
   for(ll i=1;i<V;i++){
      distance[i]=INT_MAX;
   }

   //cotains unvisited node pair(-d,x) ==>d = distance till now x = vertex (-ve bcz to treat as min heap)
   priority_queue<pair<ll,ll> > leftItem; //becs of this binary heap time complexity reduce
   leftItem.push(make_pair(0,0));
   while(!leftItem.empty()){
      ll explore = leftItem.top().second;
      leftItem.pop();
      if(visited[explore]) continue;
      visited[explore] = true;
      for(auto element : adj[explore]){
         ll b = element.first, weight = element.second;
         if(distance[explore]+weight < distance[b])
         distance[b] = distance[explore]+weight;
         leftItem.push(make_pair(-distance[b],b)); 
      }
   }

   for(ll i=0;i<V;i++)
   cout<<distance[i]<<" ";
   return 0;
}