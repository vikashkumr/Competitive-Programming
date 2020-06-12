//Dijkstra Algorithm O(ElogV) (E = Edge, V = vertex)
//implemented using adjecency List undirected Graph 
//Can be easily converted to directed Graph (chage addEdge function) 

#include <bits/stdc++.h>
using namespace std;

//adjecency list for udirected graph
void addEdge(vector<pair<int,int> >adj[], int u, int v, int value){
   adj[u].push_back(make_pair(v,value));
   adj[v].push_back(make_pair(u,value));
}

int main() {
   int V;
   cout<<"Enter no of node: 5 \n";
   // cin>>V;
   V=5;
   int u,v,value;
   vector<pair<int,int> >adj[V]; //adjecency list contain a-->b pair<b,weight(a-->b)>
   addEdge(adj,0,1,5);
   addEdge(adj,1,2,2);
   addEdge(adj,2,3,6);
   addEdge(adj,3,4,2);
   addEdge(adj,0,4,1);
   addEdge(adj,3,1,9);
   // bool visited[V]; // visited array to not compute same vertex again
   // memset(visited,false,sizeof(visited));
   int distance[V];  //record of path length from sourse to i'th vertex

   //innitialise
   distance[0]=0; 
   for(int i=1;i<V;i++){
      distance[i]=INT_MAX;
   }

   //cotains unvisited node pair(-d,x) ==>d = distance till now x = vertex (-ve bcz to treat as min heap)
   priority_queue<pair<int,int> > leftItem; //becs of this binary heap time complexity reduce //<dist, Node>
   leftItem.push(make_pair(0,0));
   while(!leftItem.empty()){
      int explore = leftItem.top().second;
      leftItem.pop();
      // if(visited[explore]) continue;
      // visited[explore] = true;
      for(auto element : adj[explore]){
         int b = element.first, weight = element.second;
         if(distance[explore]+weight < distance[b]) {
            distance[b] = distance[explore]+weight;
            leftItem.push(make_pair(-distance[b],b)); //if wanna use vis array take out this line from for loop
         } 
      }
   }

   //printing vertex and it's distance from souce vertex
   cout<<"vertex        "<<"distance from source\n";
   for(int i=0;i<V;i++)
   cout<<i<<"              "<<distance[i]<<"\n";
   return 0;
}