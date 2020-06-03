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
#define vs vector<string>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};
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

#undef int
int main(){
#define int long long 
    fast;
    int n,k;
    cin>>n>>k;
    dsu g(n);
    int res = 0;
    for(int i=0;i<k;i++) {
        int a, b;
        cin>>a>>b;
        if(g.find(a-1)==g.find(b-1)) res++;
        else g.union_set(a-1,b-1);
    }
    cout<<res;
    return 0;
}
