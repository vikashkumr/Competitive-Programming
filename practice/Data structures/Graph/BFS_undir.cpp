//BFS of undirected graph 
//adjecency list

#include<bits/stdc++.h>
using namespace std;
int visited[4]={0};
void BFS(vector<int> adj[],int data){
	queue<int>q;
	visited[data]=1;
	q.push(data);
	while(!q.empty()){
		data=q.front();
		cout<<data<<" ";
		q.pop();
		for(auto x : adj[data]){
			if(visited[x]==0){
				visited[x]=1;
				q.push(x);
			}
		}
	}
}


void BFT(vector<int> adj[],int V){
	for(int v=0;v<V;v++){
		if(visited[v]==0){
			BFS(adj,v);
		}
	}
}
void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main(){
	int V=4;
	vector<int>adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 0); 
    addEdge(adj,0, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 3); 
    BFT(adj,V);
	return 0;
}
