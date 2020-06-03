//Krushkal Algorithm

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

int findParent(int ch, int *parent) {
	if(parent[ch] == ch) {
		return ch;
	} else {
		return findParent(parent[ch],parent);
	}
}

void krushkal(Edge *input, int n, int m) {
	sort(input,input+m, cmp);
	int parent[n];
	int count = 0;
	for(int i=0;i<n;i++) parent[i] = i;
	Edge *output = new Edge[n-1];
	int i = 0;
	while(count != (n-1)) {
		Edge currEdge = input[i++];
		int srcParent = findParent(currEdge.src, parent);
		int destParent = findParent(currEdge.dest, parent);
		if(srcParent != destParent) {
			output[count++] = currEdge;
			parent[srcParent] = destParent;
		}
	}
	for(int i=0;i<count;i++) {
		Edge currEdge = output[i];
		if(currEdge.src <= currEdge.dest) {
			cout<<currEdge.src<<" "<<currEdge.dest<<" "<<currEdge.wt<<"\n";
		} else {
			cout<<currEdge.dest<<" "<<currEdge.src<<" "<<currEdge.wt<<"\n";
		}
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	Edge *input = new Edge[m];
	for(int i=0;i<m;i++) {
		cin >> input[i].src >> input[i].dest >> input[i].wt;
	}
	krushkal(input,n,m);

	return 0;
}
