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
vector<int> rn;
vector<pair<int,int> >parent;// ele, amount
void dsu(int n) {
    parent.resize(n);
    rn.resize(n);
    for(int i=0;i<n;i++) {
        parent[i].first = i;
        rn[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x].first) return x;
    return parent[x].first = find(parent[x].first); //path compression 
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(rn[a] < rn[b])
            swap(a,b);
        parent[b].first = a;
        parent[a].second = min(parent[a].second,parent[b].second);
        if(rn[a] == rn[b]) 
            rn[a]++;
    }
}

#undef int
int main(){
#define int long long 
    fast;
    int n,k;
    cin>>n>>k;
    dsu(n);
    int tmp;
    for(int i=0;i<n;i++) cin>>tmp, parent[i].second = tmp;
    for(int i=0;i<k;i++) {
        int a,b;
        cin>>a>>b;
        union_set(a-1,b-1);
    }
    int res = 0;
    int ans[n];
    for(int i=0;i<n;i++) ans[i]=0;
    for(int i=0;i<n;i++) {
        if(parent[i].first==i)
        ans[i] = parent[find(i)].second;
    };
    for(int i=0;i<n;i++) {
        res+=ans[i];
    };
    cout<<res;
    return 0;
}