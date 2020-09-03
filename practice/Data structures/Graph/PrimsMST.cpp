//Prims Algorithm O((V + E)logV) V => no of nodes, E => Edges
// Algorithm Steps:

// Maintain two disjoint sets of vertices. One containing vertices that are in the growing spanning tree and other that are not in the growing spanning tree.
// Select the cheapest vertex that is connected to the growing spanning tree and is not in the growing spanning tree and add it into the growing spanning tree. This can be done using Priority Queues. Insert the vertices, that are connected to growing spanning tree, into the Priority Queue.
// Check for cycles. To do that, mark the nodes which have been already selected and insert only those nodes in the Priority Queue that are not marked. 

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x) {
   priority_queue<PII, vector<PII>, greater<PII> > Q;
   int y;
   long long minimumCost = 0;
   PII p;
   Q.push(make_pair(0, x)); // {dist, node}
   while(!Q.empty()) {
      // Select the edge with minimum weight
      p = Q.top();
      Q.pop();
      x = p.second;
      // Checking for cycle
      if(marked[x] == true)
         continue;
      minimumCost += p.first;
      marked[x] = true;
      for(int i = 0;i < adj[x].size();++i) {
         y = adj[x][i].second;
         if(marked[y] == false)
         Q.push(adj[x][i]);
      }
   }
   return minimumCost;
}
// chandrashekar bhosle
int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}

==========================================================================================

//Prims Algorithm O(V^2) V => no of nodes 

#include <bits/stdc++.h>
using namespace std;
#define V 5

void printMST(int parent[], int Graph[][V]){
   cout<<"Edge     "<<"Weight\n";
   for(int i=1;i<V;i++){
      cout<<parent[i]<<" - "<<i<<" "<<Graph[i][parent[i]]<<"\n";
   }
}

int minKey(int key[],bool mstSet[]){
   int min=INT_MAX,min_index;
   for(int i=0;i<V;i++){
      if(mstSet[i]==false && key[i]<min){
         min = key[i]; min_index = i;
      }
   }
   return min_index;
}
void primsMST(int Graph[][V]){
   bool mstSet[V];  //represent the set of nodes not yet included in MST
   int key[V]; //used to store key value of all vertices
   int parent[V];
   for(int i=0;i<V;i++)
      key[i]=INT_MAX, mstSet[i]=false;
   key[0]=0;
   parent[0]=-1;
   for(int i=0;i<V-1;i++){
      int u = minKey(key,mstSet);
      mstSet[u]=true;

      for(int v=0;v<V;v++){
         if(Graph[u][v] && mstSet[v]==false && Graph[u][v]<key[v]){
            parent[v]=u; key[v]=Graph[u][v];
         }
      }
   }
   printMST(parent,Graph);
}

int main() {
   // int V;
   // cout<<"enter no of nodes:\n";
   // cin>>V;
   cout<<"enter adjecency mattrix element(weight) 5X5:\n";
   int Graph[V][V];

   for(int i=0;i<V;i++){
      for(int j=0;j<V;j++)
      cin>>Graph[i][j];
   }
   primsMST(Graph);
   return 0;
}