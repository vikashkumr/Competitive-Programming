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
#define FOR(i,a,b) for(int i=a;i<b;i++)
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
    int n;
    dsu g(26);
    string ar[200005];
    cin>>n;
    FOR(i,0,n) {
        string s;
        cin>>s;
        ar[i] = s;
        FOR(j,0,s.length()-1)  
        g.union_set(s[j]-'a',s[j+1]-'a');
    }
    int sp[26]={0};

    FOR(i,0,n) {
        FOR(j,0,ar[i].length()) {
            sp[g.find(ar[i][j]-'a')]++;
        }
    }
    int ans = 0;
    FOR(i,0,25) {
        if(sp[i]) ans++;
    }
    cout<<ans;
    return 0;
}