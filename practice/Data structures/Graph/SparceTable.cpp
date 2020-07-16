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
//=================================================================//

//sparce table for min range
class sparse_table {
public:
    matrix mat; // 2d matrix
    int n, m;   //size and log
    vi p2; //power of 2 
    void init(int _n, _m) {
        n = _n;
        m = _m;
        mat.resize(n);
        for(int i=0;i<n;i++) mat[i].resize(m);  
        for(int i=1;i<=n;i++) p2[i] = p2[i/2] + 1; // log property     
    }

    void build(int a[]) {
        for(int i=0;i<n;i++) mat[i][0] = a[i];
        for (int j = 1; j < m; j++) {
            for (int i = 0; i +(1<<j) <= n; i++) {
                mat[i][j] = min(mat[i][j-1], mat[i+(1 << (j-1))][j-1]);
                // mat[i][j] = mat[i][j-1] + mat[i+(1 << j)][j-1];// for sum
            }
        }
    }

    int query(int l, int r) {
        int pw = p2[r-l];
        return min(mat[l][pw], mat[r-(1<<pw) + 1][pw]);
    }


}

int32_t main(){
    fast;
    
    
    return 0;
}