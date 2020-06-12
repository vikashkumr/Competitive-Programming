#include<bits/stdc++.h>
#include<queue>
 
using namespace std;
const int M =1e3 + 5;
const int inf = 1e9;
 
int n,m,k,sx,sy,ex,ey;
char s[M][M];
int go[4][2] = {1,0,-1,0,0,1,0,-1};
int dis[M][M];
 
void bfs() {
	
	queue<pair<int,int> > q;
	q.push(make_pair(sx,sy));
	dis[sx][sy] = 0;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
				q.pop();
		
		for(int i=0;i<4;i++) {
			for(int j=1;j<=k;j++) {
				int dx = x + j*go[i][0];
				int dy = y + j*go[i][1];
				if(dx<1 || dx>n || dy<0 || dy>m || s[dx][dy]!='.' || dis[dx][dy] < dis[x][y] + 1)
					break;
				if(dis[dx][dy] == inf)
					dis[dx][dy] = dis[x][y] + 1,
					q.push(make_pair(dx,dy));
			}
		}
	}
	
	return ;
}
 
 
 
int main() {
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
	}
	scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			dis[i][j] = inf;
		}
	}
	
	bfs();
	printf("%d\n", dis[ex][ey] == inf ? -1 : dis[ex][ey] );
}