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
#define vp vector<pii>
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int sz = 100005;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//
int n;
int ans = 0;
void bfs(int src, vector<int> g[]) {
    vector<int> dist(n+1,INT_MAX);
    queue<pair<int,int>> q;
    q.push({src,src});
    dist[src] = 0;

    while(!q.empty()) {
        auto curr = q.front();q.pop();
        for(auto child: g[curr.first]) {
            if(dist[child] == INT_MAX) {
                dist[child] = 1 + dist[curr.first];
                q.push({child,curr.second + child});
            }
            else if(dist[child] <= dist[curr.first] and child==src) {
                ans = max(ans, curr.second);
            }
        }
    }
}

int32_t main(){
    fast;
    test() {
        cin>>n;
        vector<int> g[n];
        for(int u=0;u<n;u++) {
            int v;
            cin>>v;
            if(v!=-1) g[u].push_back(v); 
        }
        for (int i = 0; i < n; i++) {
            bfs(i,g);
        }
        cout<<ans<<endl;
    }
    return 0;
}