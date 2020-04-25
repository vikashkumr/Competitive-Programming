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
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//
int maxor = -1;
int k;
void solve(int res, int idx, int n, int *arr,int no) {
    if(idx==n and no==k) {
        maxor = max(maxor,res);
        return;
    }

    if(idx>=n) return;

    //consider that idxTh element
    solve(res^arr[idx],idx+1,n,arr,no+1);

    //don't consider
    solve(res,idx+1,n,arr,no);

}



#undef int
int main(){
#define int long long 
    fast;
    test() {
        int n;
        cin>>n>>k;
        int arr[n];
        FOR(i,0,n-1) cin>>arr[i];
        maxor = -1;
        solve(0,0,n,arr,0);
        cout<<maxor<<endl;
    }   
    
    return 0;
}