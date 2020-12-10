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
    vector<int>rank,parent;
public:
    dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++) parent[i] = i, rank[i] = 0;
    }

    int find(int n) {
        if(n == parent[n]) return n;
        return parent[n] = find(parent[n]);
    }

    void make_set(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            if(rank[y] > rank[x])
            swap(x,y);
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};

int cnt[200005][26]; ///kitno bcho ka super parent h uska count
#undef int
int main(){
#define int long long 
    fast;
    test() {
        int k,n;
        cin>>n>>k;
        string s;
        cin>>s;
        dsu g(n);
        for(int i=0;i<n;i++) g.make_set(i,n-1-i);
        for(int i=0;i<n-k;i++) g.make_set(i,k+i);
        for(int i=0;i<n;i++) {
            for(int j=0;j<26;j++) cnt[i][j] = 0;
        }
        for(int i=0;i<n;i++) {
            cnt[g.find(i)][s[i]-'a']++;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(g.find(i)==i) {
                int sum = 0;
                int mx_occur_char = 0;
                for(int j=0;j<26;j++) {
                    sum+=cnt[i][j];
                    mx_occur_char = max(mx_occur_char,cnt[i][j]);
                }
                ans+=sum-mx_occur_char;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}














