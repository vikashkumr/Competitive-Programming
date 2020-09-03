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
    int N;
    cin>>N;
    vi g[N];
    vi arr(N+1);
    for(int i=2;i<=N;i++) {
        int tmp;
        cin>>tmp;
        g[i].push_back(tmp);
        g[tmp].push_back(i);
    }

    for(int i=1;i<=N;i++) {
        cin>>arr[i];    
    }
    int step = 0;
    queue<pair<int,int>> q;
    q.push({1,-1}); // node number and val
    while(!q.empty()) {
        auto node = q.front(); q.pop();
        if(node.second == arr[node.first]) continue;
        //run bfs and insert all value to queue
        queue<pair<int,int>> tmpq;
        vi vis(N+1, 0);
        vis[1] = 1;
        for(auto child: g[node.first]) {
            tmpq.push({child, arr[1]});
        }
        while(!tmpq.empty()) {
            if()
        }
        step++;
    }

    cout<<step<<endl;
    
    return 0;
}