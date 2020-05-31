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
int n,m;
char maze[11][11];
bool solve(int r, int c) {
    if(r==n-1 and c==m-1 and maze[r][c]=='O') {
		maze[r][c] = '1';
        FOR(i,0,n-1) {
            FOR(j,0,m-1) {
                if(maze[i][j]=='1')
                cout<<1<<" ";
                else cout<<0<<" ";
            }
            cout<<endl;
        }
        return true;
    } 
    if(r<0 or c<0 or r>=n or c>=m ) return false;

    if(maze[r][c]=='X' or maze[r][c]=='1') return false;
    maze[r][c] = '1';
    if(solve(r+1,c) || solve(r,c+1) || solve(r-1,c) || solve(r,c-1)) {
        return true;
    } else 
    maze[r][c] = 'O';
    return false;
}



#undef int
int main(){
#define int long long 
    fast;
    cin>>n>>m;
    FOR(i,0,n-1)
        FOR(j,0,m-1)
            cin>>maze[i][j];
    bool ans = solve(0,0);
    if(!ans)
    cout<<"NO PATH FOUND";
    
    return 0;
}