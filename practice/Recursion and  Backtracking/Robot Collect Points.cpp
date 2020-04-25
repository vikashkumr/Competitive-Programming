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
int solve(int i, int j, int grid[][5]) {
    if(i<0 or j<0 or j>=5) return 0;
    int x =grid[i][j] + solve(i-1,j-1,grid);
    int y =grid[i][j] + solve(i-1,j,grid);
    int z =grid[i][j] + solve(i-1,j+1,grid);
    return max(x,max(y,z));
}

int min(int a, int b) {
	return a<b?a:b;
}
#undef int
int main(){
#define int long long 
    fast;
    test() {
        int h;
        cin>>h;
        int grid[h+1][5]={0};
        FOR(i,0,h-1) {
            FOR(j,0,4) {
                cin>>grid[i][j];
            }
        }
        int ans = INT_MIN;
        int flipgrid[5][5] = {0};
        FOR(k,0,h-5){
            FOR(i,k,min(h-1+k,4+k)) {
                FOR(j,0,4) {
                    if(grid[i][j]==-1) {
                        grid[i][j] = 0;
                        flipgrid[i-k][j] = -1;
                    }
                }
            }
            ans = max(ans,solve(h,2,grid));
            //to normalize each grid again
            FOR(i,k,min(h-1+k,4+k)) {
                FOR(j,0,4) {
                    if(flipgrid[i-k][j]==-1) {
                        grid[i][j] = -1;
                        flipgrid[i-k][j] = 0;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }    
    return 0;
}