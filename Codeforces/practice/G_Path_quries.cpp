// Path Queries
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 200005

/*
Logic: DSU, Prefix Sum

Here we store edges first and then sort them. Them pick edges one by one by sroting theiry weight.
Node_count store the no of nodes in a particular component.

Key observation is that, we are given a tree so no cycle, so when ever whe union two vertices that belong to diff component.
So total combination of vertices pair will be (nodes in one comp * nodes in second comp).

After cal result we merge them into one compoennt.
*/

vector<ll>prefix(MAX, 0);

class DSU{
    vector<ll>parent, node_count;
    
    public:
    DSU(ll v){
        parent = vector<ll>(v);
        node_count = vector<ll>(v);

        for(ll i=0; i<v; i++){
            parent[i]=i;
            node_count[i]=1;
        }
    }

    ll get(ll a){
        if(parent[a] == a){
            return a;
        }
        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(node_count[a]<node_count[b]){
                swap(a,b);
            }
            parent[b]=a;
            node_count[a] += node_count[b];
        }
    }

    ll getNodeCount(ll a){
        a = get(a);
        return node_count[a];
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;

    vector<vector<ll> >edges;
    for(ll i=1; i<n; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }   
    
    sort(edges.begin(), edges.end());
    DSU g(n+1);

    for(ll i=0; i<n-1; i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        // remember the given grpah is tree 9i.e without any cycles).
        // so when we multiply thieri size it is sure that they belong to diff component
        prefix[w] += g.getNodeCount(u)*g.getNodeCount(v);
        g.union_sets(u,v);
        // debug(prefix[w]);
    }

    for(ll i=1; i<MAX; i++){
        prefix[i] += prefix[i-1];
    }

    while(m--){
        ll w;
        cin>>w;
        cout<<prefix[w]<<" ";
    }
    cout<<endl;
    return 0;
}
