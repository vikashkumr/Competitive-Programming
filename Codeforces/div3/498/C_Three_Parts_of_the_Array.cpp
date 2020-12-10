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
    int n; cin>>n;
    int a[n];
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];       
    }
    if(n==1) {
        cout<<0<<endl;
        exit(0);
    }
    sum/=2;
    int pre[n], suff[n];
    pre[0] = a[0];
    suff[n-1] = a[n-1];
    for(int i=1;i<n;i++) pre[i] = a[i] + pre[i-1];
    for(int i=n-2;i>=0;i--) suff[i] = a[i] + suff[i+1];
    reverse(suff,suff+n);
    int idx = lower_bound(pre,pre+n,sum)-pre;
    for(int i=idx;i>=0;i--) {
        if(suff[lower_bound(suff,suff+n,pre[i])-suff]==pre[i]) {
            cout<<pre[i]<<endl;
            exit(0);
        }
    }
    cout<<0<<endl;
    
    return 0;
}