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
const int N = 100005;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//

vector<int> gr[N];
int disc[N], low[N], timer; //discovery time and lowest time
set<int> art_p;
vector<pair<int,int>> bridges;

void dfs(int curr, int par) {
    disc[curr] = low[curr] = timer++;
    int no_of_child = 0;
    for(auto child: gr[curr]) {
        //not visited
        if(disc[child]==0) {
            dfs(child, curr);
            no_of_child++;
            low[curr] = min(low[curr], low[child]);
            //art point
            if(par != 0 && low[child] >= disc[curr]) {
                art_p.insert(curr);
            }
            //bridges
            if(low[child] > disc[curr]) {
                bridges.push_back({curr, child});
            }
        }
        else if(child != par) {
            //backedge
            //cycle found
            low[curr] = min(low[curr], disc[child]);
        }
    }
    // seprate case for root to be articulation point
    if(par == 0 && no_of_child >= 2) {
        art_p.insert(curr);
    }
    return;
}


void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int x, y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);       
    }

    timer = 1;
    dfs(1, 0);
}

int32_t main() {
    solve();
    return 0;
}