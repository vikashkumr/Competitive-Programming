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


#undef int
int main(){
#define int long long 
    fast;
    int n;
    cin>>n;
    double arr[n];
    int dupli[n];
    FOR(i,0,n-1) cin>>arr[i], dupli[i] = floor(arr[i]);
    int sum = accumulate(dupli,dupli+n,0);
    int i = 0;
    while(sum!=0) {
        if(floor(arr[i])!=arr[i]) dupli[i]++, sum++;
        i++;
    }
    FOR(i,0,n-1) cout<<dupli[i]<<" ";
    return 0;
}