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
class dsu {
    vector<int>parent, rank;
    int totalComponents;
public:
    dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        totalComponents = n;
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]); //path compression 
    }

    void union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(rank[a] < rank[b])
                swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) 
                rank[a]++;
            totalComponents--;
        }
    }
};
class Edge {
public:
    int src, dest, wt;
};


int m,n;


int32_t main(){
    fast;
    cin>>m>>n;
    while(m and n) {
        int total = 0;
        Edge *input = new Edge[n];
        for(int i=0;i<n;i++) {
            cin>>input[i].src>>input[i].dest>>input[i].wt;
            total += input[i].wt;
        }
        sort(input, input+n,[&](Edge a, Edge b) -> bool {
            return a.wt < b.wt;
        });

        dsu g(m+1);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int u = input[i].src;
            int v = input[i].dest;
            int w = input[i].wt;
            if(g.find(u) != g.find(v)) {
                ans += w;
                g.union_set(u,v);
            }
        }
        cout<<total-ans<<endl;
        cin>>m>>n;
    }
    
    return 0;
}