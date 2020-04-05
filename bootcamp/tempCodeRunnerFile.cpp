// STL implementation of Prim's algorithm for MST 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 

// To add an edge 
void addEdge(vector <pair<int, int> > adj[], int u, 
									int v, int wt) 
{ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
} 

// Prints shortest paths from src to all other vertices 
void primMST(vector<pair<int,int> > adj[], int V) 
{ 
	priority_queue< iPair > pq; 

	int src = 0; // Taking vertex 0 as source 

	// Create a vector for keys and initialize all 
	// keys as infinite (INF) 
	vector<int> key(V, INF); 

	// To store parent array which in turn store MST 
	vector<int> parent(V, -1); 

	// To keep track of vertices included in MST 
	vector<bool> inMST(V, false); 

	// Insert source itself in priority queue and initialize 
	// its key as 0. 
	pq.push(make_pair(0, src)); 
	key[src] = 0; 

	/* Looping till priority queue becomes empty */
	while (!pq.empty()) 
	{ 
		// The first vertex in pair is the minimum key 
		// vertex, extract it from priority queue. 
		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted key (key must be first item 
		// in pair) 
		int u = pq.top().second; 
		pq.pop(); 

		inMST[u] = true; // Include vertex in MST 

		// Traverse all adjacent of u 
		for (auto x : adj[u]) 
		{ 
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = x.first; 
			int weight = x.second; 

			// If v is not in MST and weight of (u,v) is smaller 
			// than current key of v 
			if (inMST[v] == false && key[v] > weight) 
			{ 
				// Updating key of v 
				key[v] = weight; 
				pq.push(make_pair(key[v], v)); 
				parent[v] = u; 
			} 
		} 
	} 

	// Print edges of MST using parent array 
	for (int i = 1; i <V; ++i) 
		printf("%d - %d\n", parent[i], i); 
} 

// Driver program to test methods of graph class 
int main() 
{ 

	// making above shown graph 
    int n,m,s;
    cin>>n>>m>>s;

    vector<iPair> adj[n];
    for(int i=0;i<m;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        addEdge(adj,u-1,v-1,c);
    } 
  

	primMST(adj, n); 

	return 0; 
} 
