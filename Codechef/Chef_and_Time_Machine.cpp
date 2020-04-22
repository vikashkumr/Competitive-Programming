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
#define aint(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//
multiset<int>mst;
#undef int
int main() {
#define int long long 
    fast;
    test() {
        mst.clear();
        int n, k, m, t1, t2;
        cin >> n >> k >> m;
        int diff[n];
        k = k+m;
        int arr[k];
        FOR(i,0,n-1) {
            cin>>diff[i];
        }
        FOR(i,0,n-1) {
            cin>>t1;
            diff[i]-=t1;
        }
        FOR(i,0,k-1) {
            cin>>t1;
            mst.insert(t1);
        }

        FOR(i,0,n-1) {
            multiset<int>:: iterator it = mst.lower_bound(diff[i]);
            // debug(*it);
            if((diff[i]-*(it))==0) {
                diff[i] = 0;
                mst.erase(it);
            } else {
                if(it!=mst.begin()) {
                    diff[i] = diff[i]-*(--it);
                    mst.erase(it);
                }
            }
        }
        int sum = 0;
        FOR(i,0,n-1) sum+=diff[i];
        cout<<sum<<endl;
    }
    
    return 0;
}
