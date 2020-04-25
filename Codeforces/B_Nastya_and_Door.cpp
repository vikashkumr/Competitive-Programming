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
    test() {
        int n,k;
          cin>>n>>k;
        int arr[n+1];
        // k=k-1;
        FOR(i,1,n) {
            cin>>arr[i];
        }

        bool corn[n+1]={0};
        FOR(i,2,n-1) {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) corn[i] = 1;
        }
        int ans = INT_MIN;
        int strtIndex = 2;
        int cntcorner = 0;
        int l = 2, r = k-1;
        FOR(i,l,r) {
            if(corn[i]) cntcorner++;
        }
        ans = max(cntcorner,ans);

        FOR(i,k,n-1) {
            cntcorner+=corn[i];
            cntcorner-=corn[l++];
            if(cntcorner>ans) {
                ans = cntcorner;
                strtIndex = l;
            }
        }
        cout<<ans+1<<" "<<strtIndex-1<<endl;
    }   
    
    return 0;
}