#include<bits/stdc++.h>
using namespace std;
const int N=3e5;

int arr[N],dp[N];
vector<int>adj[N];
void dfs(int u,int par){
    dp[u] = arr[u];
    int mx=0;
    for(int child : adj[u]){
        if(child == par) continue;
        dfs(child,u);
        mx = max(mx,dp[child]);
    }
    dp[u]+=mx;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V,u,v;
    cin>>V;
    for(int i=1;i<V;i++) cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
    for(int i=1;i<=V;i++) cin>>arr[i];
    dfs(1,0);

    cout<<dp[1];

}

/* for single query this can be deone without dp
#include<bits/stdc++.h>
using namespace std;
const int N=3e5;

int arr[N];
vector<int>adj[N];
int dfs(int u,int par){
    // dp[u] = arr[u];
    int mx=0;
    //cout<<mx+arr[u]<<" ";
    for(int child : adj[u]){
        if(child == par) continue;
        mx = max(mx,dfs(child,u));
    }
    // dp[u]+=mx;
    
    return mx+arr[u];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V,u,v;
    cin>>V;
    for(int i=1;i<V;i++) cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
    for(int i=1;i<=V;i++) cin>>arr[i];
    cout<<dfs(1,0);

    //cout<<dp[1];

}

*/