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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];      
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        int x = a[i];
        for(int bit=30;bit>=0;bit--) {
            int idx1 = lower_bound(a,a+n,x+(1<<bit))-a;
            int idx2 = lower_bound(a,a+n,x-(1<<bit))-a;
            if(idx1 < n and a[idx1]==x+(1<<bit)) idx1 = 1;
            else idx1 = 0;
            if(idx2 < n and a[idx2]==x-(1<<bit)) idx2 = 1;
            else idx2 = 0;
            if(idx1 > 0 and idx2 > 0) {
                cout<<3<<endl;
                cout<<x-(1<<bit)<<" "<<x<<" "<<x+(1<<bit)<<endl;
                exit(0);
            }
        }  
    }
    for(int i=0;i<n;i++) {
        int x = a[i];
        for(int bit=30;bit>=0;bit--) {
            int idx1 = lower_bound(a,a+n,x+(1<<bit))-a;
            int idx2 = lower_bound(a,a+n,x-(1<<bit))-a;
            if(idx1 < n and a[idx1]==x+(1<<bit)) idx1 = 1;
            else idx1 = 0;
            if(idx2 < n and a[idx2]==x-(1<<bit)) idx2 = 1;
            else idx2 = 0;
   
            if(idx1 > 0 || idx2 > 0) {
                cout<<2<<endl;
                if(idx2>0) cout<<x-(1<<bit)<<" "<<x<<endl;
                if(idx1>0) cout<<x<<" "<<x+(1<<bit)<<endl;
                exit(0);
            }
        }     
    }
    cout<<1<<endl;
    cout<<a[0]<<endl;
    return 0;
}