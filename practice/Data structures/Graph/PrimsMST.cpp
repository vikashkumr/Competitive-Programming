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