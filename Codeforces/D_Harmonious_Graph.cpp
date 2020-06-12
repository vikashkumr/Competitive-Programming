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
//=================================================================//

class dsu {
    vector<int> parent;
public:
    dsu(int n) {
        parent.resize(n+1);
        for(int i=1;i<=n;i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]); //path compression 
    }

    void union_set(int a, int b) {
        a = find(a);
        b = find(b);
        parent[min(a, b)] = max(a, b);
    }
};

int32_t main(){
    fast;
    int n,m;
    cin >> n >> m;
    dsu g(n);
    for (int i = 1; i <= m;i++) {
        int u, v;
        cin >> u >> v;
        g.union_set(u, v);
    }
    int ans = 0;
    int j = 1;
    for (int i = 1; i <= n;i++) {
        int mx = g.find(i);
        for (; j <= mx;j++) {
            if(g.find(j) != g.find(i)) {
                ans++;
                g.union_set(j, mx);
            }
        }
        j = mx + 1;
    }
    cout << ans;
    return 0;
}