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

vector<pair<int,int>> parent;
vector<int> rnk;
int find(int x) {
    if(parent[x].first == x) return x;
    return parent[x].first = find(parent[x].first);
}

int32_t main(){
    fast;
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    rnk.resize(n+1);
    for(int i=1;i<=n;i++) {
        parent[i].first = i;
        parent[i].second = 1;
        rnk[i] = 0;       
    }
    for(int i=0;i<m;i++) {
        int tmp; cin>>tmp;
        int last;
        for(int j=0;j<tmp;j++) {
            int x; cin>>x;
            if(j==0) {
                last = x;
                continue;
            }
            int p1 = find(x);
            int p2 = find(last);
            if(p1==p2) continue;
            else {
                if(rnk[p1]< rnk[p2]) swap(p1,p2);
                parent[p2].first = p1;
                parent[p1].second = parent[p1].second + parent[p2].second;
                if(rnk[p1]==rnk[p2]) rnk[p1]++;
            }
            last = x;
        }
    }
    for(int i=1;i<=n;i++) {
        int x = find(i);
        cout<<parent[x].second<<" ";
    }
    
    return 0;
}