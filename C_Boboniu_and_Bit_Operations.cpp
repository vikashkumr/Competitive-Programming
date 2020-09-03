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
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];       
    }
    int b[m];
    for(int i=0;i<m;i++) {
        cin>>b[i];       
    }
    for(int i=0;i<n;i++) {
        int x = INT_MAX;
        for(int j=0;j<m;j++) {
            x = min(x, a[i]&b[j]);
        }
        a[i] = x;
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans |= a[i];       
    }
    cout<<ans;
    return 0;
}