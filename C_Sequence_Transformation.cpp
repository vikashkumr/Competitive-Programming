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


int32_t main(){
    fast;
    test() {
       unordered_map<int,int> last_idx, still_last_idx;
       map<int,int> mp;
       int n;
       cin>>n;
       int a[n];
       bool ok = 0;
       cin>>a[0];
       last_idx[a[0]] = -1;
       int x = a[0];
       for(int i=1;i<n;i++) {
           cin>>a[i];
           last_idx[a[i]] = -1;
           if(a[i]!=x) ok = 1;
       }
       if(!ok) {
           cout<<0<<endl;
           continue;
       }
       for(int i=0;i<n;i++) {
            if((i-last_idx[a[i]]) > 1) {
                mp[a[i]]++;
            }       
            last_idx[a[i]] = i;
       }
       int ans = INT_MAX;
       for(int i=0;i<n;i++) {
           int k = 0;
           if(last_idx[a[i]]!=n-1) k++;
           k+=mp[a[i]];
           if(k < ans) {
               ans = k;
           }
       }
        cout<<ans<<endl;
    }
    
    return 0;
}