#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
#define matrix vector<vector<int> >
#define vi vector<int>
#define pii pair<int,int>
#define vs vector<string>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//=================================================================//
const int N = 200000 + 10;
int n,m,k,p[N],dis[N],can[N];
vector<int> g[N];

#undef int
int main(){
#define int long long 
    fast;
    cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
        cin >> u >> v;
        g[v].push_back(u);
    }
	cin >> k;
	for(int i=1;i<=k;i++)cin>>p[i];
	memset(dis,-1,sizeof(dis));
	dis[p[k]]=0; 
	queue<int> q; q.push(p[k]);
	while(q.size()){
		int u=q.front(); q.pop();
		for(auto v:g[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1; q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(auto v:g[i]){
			if(dis[v]==dis[i]+1){
				can[v]++;
			}
		}
	}
	//printf("dis = %d\n", dis[p[1]]);
	int mn=0,mx=0;
	for(int i=1;i<k;i++){
		if(dis[p[i]]<=dis[p[i+1]])mn++,mx++;
		else {
			if(can[p[i]]>=2)mx++;
		}
	}
	cout<<mn<<" "<<mx<<endl;
    
    return 0;
}
