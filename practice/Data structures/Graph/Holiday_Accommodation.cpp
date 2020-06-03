#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
typedef long double ld;
typedef vector<vector<int> > matrix;
typedef vector<int> arr;
typedef vector<string> vs;
typedef vector<pair<int,int> > pv;
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};
//=================================================================//

int n;
unordered_map<int, list<pair<int,int>>> adj;

int dfs(int node,unordered_map<int,bool> &vis,int* count,int &ans){ // dfs is giving the count of subtrees nodes
		vis[node] = true;
		count[node] = 1;

		for(auto children:adj[node]){
			int dx = children.second;
			if(!vis[children.first]){
				count[node] += dfs(children.first,vis,count,ans);
				int right = count[children.first];
				int left = n - right;
				ans += 2*min(left,right)*dx;
			}
		} 
		return count[node];
	}

	int holiday(){
		unordered_map<int,bool> vis;
		int count[n];
		
		for(int i = 0 ; i < n ; i++)
			count[i] = 0;
		int ans = 0;
		dfs(0,vis,count,ans);
		return ans;
	}



#undef int
int main(){
#define int long long 
    fast;
    int counter = 1;
    test() {
		adj.clear();
        cin>>n;
        FOR(i,1,n-1) {
            int u, v, w;
            cin>>u>>v>>w;
            adj[u-1].push_back({v-1,w});
            adj[v-1].push_back({u-1,w});
        }
        cout<<"Case #"<<counter<<": "<<holiday()<<endl;
        counter++;
    }
    
    return 0;
}