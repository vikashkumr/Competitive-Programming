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
const int sz = 100005;
//=================================================================//
int dis[25][25];
char grid[25][25];
int src_x, src_y, dest_x, dest_y;
int col, row;
bool posSahiHai(int r, int c) {
    return r>=0 and r<row and c>=0 and c<col and grid[r][c]!='X';
}


void dijkshtra() {
    dis[src_x][src_y] = 0;
    queue<pii> Q;
    Q.push({src_x, src_y});
    while(!Q.empty()) {
        auto curr_cell = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int x = dx[i] + curr_cell.first;
            int y = dy[i] + curr_cell.second;
            if(posSahiHai(x,y) and (dis[x][y] > (dis[curr_cell.first][curr_cell.second] + grid[curr_cell.first][curr_cell.second]-'0'))) {
                dis[x][y] = dis[curr_cell.first][curr_cell.second] + (grid[curr_cell.first][curr_cell.second]-'0');
                Q.push({x,y});
            }
        }
    }
}


int32_t main(){
    fast;
    cin >> col >> row;
    while(col and row) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin>>grid[i][j];
                if(grid[i][j] == 'S') src_x = i, src_y = j, grid[i][j] = '0';
                if(grid[i][j] == 'D') dest_x = i, dest_y = j, grid[i][j] = '0'; 
                dis[i][j] = 1e9; 
            }
        }
        dijkshtra();
        cout<<dis[dest_x][dest_y]<<endl; 
        cin>>col>>row; 
    }
    return 0;
}