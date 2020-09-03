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


int32_t main(){
    fast;
    int n, m;
    cin>>n>>m;
    queue<pair<int,int>> q;
    vector<vector<char>> in(n,vector<char>(m));
    vector<vector<int>> out(n,vector<int>(m,-1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>in[i][j];   
            if(in[i][j] == 'E') {
               q.push({i,j});
            }   
        }
    }
    bool vis[n][m] = {0};
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int cnt = 0;
    while(!q.empty()) {
        cnt++;
        int sz = q.size();
        for(int i=0;i<sz;i++) {
            auto node = q.front(); q.pop();
            for(int k=0;k<4;k++) {
                int x = node.first + dx[k];
                int y = node.second + dy[k];
                if(x>=0 and x<n and y>=0 and y<m and in[x][y]!='B' and in[x][y]!='E' and !vis[x][y]) {
					if(out[x][y] < 0)
                    out[x][y] = cnt;
                    q.push({x,y});
                }
            }
            vis[node.first][node.second] = 1;
        }
    }
	
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}