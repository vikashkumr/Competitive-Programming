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
int n, u;

void add(int i, int val, vi &BIT) {
    i++;
    while(i<=n) {
        BIT[i]+=val;
        i+=(i&(-i));
    }
}

int query(int i, vi &BIT) {
    i++;
    int ans = 0;
    while(i>0) {
        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;
}


int32_t main(){
    fast;
    test() {
        cin>>n>>u;
        vi BIT(n+5,0);
        for(int i=0;i<u;i++) {
            int l,r,val;
            cin>>l>>r>>val;
            add(l, val, BIT);
            add(r+1, -val, BIT);
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++) {
           int idx;
           cin>>idx;
           cout<<query(idx,BIT)<<endl;  
        }
    }
    return 0;
}