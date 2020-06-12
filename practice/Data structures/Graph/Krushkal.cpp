//Krushkal Algorithm
//weighted undirected graph

#include<bits/stdc++.h>
using namespace std;
int ans = 0;
//int cnt = 0;
class Edge {
	public:
	int src;
	int dest;
	int wt;
};

bool cmp(Edge e1, Edge e2) {
	return e1.wt < e2.wt;
}

class dsu {
	vector<int>parent, rank;
	int totalComponents;
public:
	dsu(int n) {
		parent.resize(n);
		rank.resize(n);
		for(int i=0;i<n;i++) {
			parent[i] = i;
			rank[i] = 0;
		}
		totalComponents = n;
	}

	int find(int x) {
		if(x == parent[x]) return x;
		return parent[x] = find(parent[x]); //path compression 
	}

	void union_set(int a, int b) {
		a = find(a);
		b = find(b);
		if(a != b) {
			if(rank[a] < rank[b])
				swap(a,b);
			parent[b] = a;
			if(rank[a] == rank[b]) 
				rank[a]++;
			totalComponents--;
		}
	}
};

void krushkal(Edge *input, int n, int m) {
	sort(input,input+m, cmp);
	dsu g(n);
	int min_weight = 0;
	for(int i=0;i<m;i++) {
		if(g.find(input[i].src) != g.find(input[i].dest)) {
			min_weight += input[i].wt;
			g.union_set(input[i].src, input[i].dest);

			//printing part
			if(input[i].src <= input[i].dest) {
			cout<<input[i].src<<" "<<input[i].dest<<" "<<input[i].wt<<"\n";
			} else {
				cout<<input[i].dest<<" "<<input[i].src<<" "<<input[i].wt<<"\n";
			}
			//
		}
	}
	cout << "min_weight: " << min_weight << endl;
}

int main() {
	int n,m;
	//m-edges n-nodes
	cin >> n >> m;
	Edge *input = new Edge[m];
	for(int i=0;i<m;i++) {
		cin >> input[i].src >> input[i].dest >> input[i].wt;
	}
	cout << endl << "src " << "dest " << "wt for MST" << endl;
	krushkal(input, n, m);

	return 0;
}
