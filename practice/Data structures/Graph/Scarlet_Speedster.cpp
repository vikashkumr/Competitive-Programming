#define pb push_back
#define ff first
#define ss second
#define ll long long
#define maxn 105
#define mod 10000007
#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int A[maxn][maxn], visited[maxn][maxn];
int n, m, a, b;

bool valid(int x, int y){
    if(x >= 1 && x<=n && y>=1 && y <=m && !visited[x][y]) return true;
    return false;
}

int bfs1(int flag){
    int ans = 0;
    deque<pair<pair<int, int>, int>> Q;
    Q.push_front({{1, 1}, 0});
    visited[1][1] = 1;
    while(!Q.empty()){
        auto node = Q.front();
        Q.pop_front();
        int x = node.ff.ff;
        int y = node.ff.ss;
        int d = node.ss;
        if(x == n && y == m) return d;
        for(int i=0;i<4;i++){
            int p, q;
            p = x + dx[i];
            q = y + dy[i];

            if(!valid(p, q)) continue;
            //cout << p << " "<< q << endl;
            visited[p][q] = true;
            if(!flag){
                if( (A[p][q]%2) == ((A[x][y])%2) ){
                    Q.push_front({{p, q}, d});
                }
                else{
                    Q.push_back({{p, q}, d + 1});
                    ans++;
                }
            }
            else{
                if( (A[p][q]%2) != ((A[x][y])%2) ){
                    Q.push_front({{p, q}, d});
                }
                else{
                    Q.push_back({{p, q}, d + 1});
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        memset(A, 0, sizeof A);

        cin >> n >> m >> a >> b;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> A[i][j];
            }
        }
        memset(visited, 0, sizeof visited);
        ll d1 = bfs1(0);
        memset(visited, 0, sizeof visited);
        ll d2 = bfs1(1);
        d1 *= a;
        d2 *= b;
        //cout << d1 << " "<< d2 << endl;
        if(d1 < d2) cout <<"YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}