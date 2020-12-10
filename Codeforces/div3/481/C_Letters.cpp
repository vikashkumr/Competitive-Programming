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
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];       
    }
    int b[k];
    for(int i=0;i<k;i++) {
        cin>>b[i];       
    }

    for(int i=1;i<n;i++) {
        a[i]+=a[i-1];       
    }
    for(int i=0;i<k;i++) {
        int cur = b[i];
        int idx = lower_bound(a,a+n,cur)-a;
        if(idx==0) cout<<idx+1<<" "<<cur<<endl;
        else cout<<idx+1<<" "<<cur-a[idx-1]<<endl;
    }

    return 0;
}