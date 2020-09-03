#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXLOG 18

int h[MAXN]; 
int par[MAXN][MAXLOG]; // initially all -1
vector <int> adj[MAXN], costs[MAXN];

void dfs(int v,int p = -1){
	par[v][0] = p;
	if(p + 1)
		h[v] = h[p] + 1;
	for(int i = 1;i < MAXLOG;i ++)
		if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : adj[v])	
		if(p - u)
			dfs(u,v);
}

int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] + 1 and h[par[v][i]] >= h[u])
			v = par[v][i];
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int main() {
	memset(par, -1, sizeof(par));
	int n;
	cin>>n;
	for(long i=1; i<n; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			u--; v--;
			adj[u].push_back(v);
			costs[u].push_back(c);
			adj[v].push_back(u);
			costs[v].push_back(c);
	}
	h[0]=0;
	dfs(0,-1);
	int q;
	cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		cout<<LCA(a-1, b-1)+1<<endl;
	}
	return 0;
}