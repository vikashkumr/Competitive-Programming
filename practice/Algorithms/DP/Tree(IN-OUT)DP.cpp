//count max height DP(2) type IN-OUT DP 
//print n value whire ith value is height of tree when i is considerd as a root

#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vector<int> g[N];
int a[N], in[N], out[N], dp[N];

//to find in height in[i]
void dfs1(int u, int par){
	in[u] = 0;
	for(int v:g[u]){
		if (v == par) continue;
		dfs1(v, u);
		in[u] = max(in[u], 1+in[v]);
	}
}

//to find out[i]
void dfs2(int u, int par){
	int mx1(-1), mx2(-1);
    
    //find top 2 maximum values of in[v]
    for(int v: g[u]){
		if(v == par) continue;
		if(in[v] >= mx1) mx2 = mx1, mx1 = in[v];
		else if(in[v] > mx2) mx2 = in[v];
	}
	for(int v:g[u]){
		if (v == par) continue;
		int use = mx1;
		
		if(mx1 == in[v]) 
			use = mx2;
		
		out[v] = max(1+out[u], 2+use);
		
		dfs2(v, u);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,u,v;
    
	cin >> n;
	fo(i, n-1){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	
	Fo(i, 1, n+1){
		dp[i] = max(in[i], out[i]);
		cout << dp[i] << " " ;
	}

	return 0;
} 

