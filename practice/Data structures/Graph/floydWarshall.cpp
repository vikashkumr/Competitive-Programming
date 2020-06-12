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
#define vs vector<string>
#define pii pair<int,inr>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//=================================================================//
vector<vector<int>> dist(11, vector<int>(11));
int n, m;

void floydWarshall() {
    for (int k = 0; k < n;k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // for (int i = 1; i <= n;i++) 
    //     if(dist[i][i] < 0) cout<<"Negative cycle is present";

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            cout << dist[i][j]<<" ";
        }
        cout << endl;
    }
}

#undef int
int main(){
#define int long long 
    fast;
    cin >> n >> m;
    
    //initializing with infinity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    floydWarshall();
    return 0;
}


/*input

4 5
1 2 1
1 4 5
2 3 3
2 4 1
4 3 1

*/