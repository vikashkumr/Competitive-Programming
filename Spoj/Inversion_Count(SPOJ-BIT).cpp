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
const int sz = 1e7;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//

// BIT[i] == how many elements are <= i


void add(int i, vi &BIT) {
    while(i<=sz) {
        BIT[i]+=1;
        i += i&(-i);
    }
}

int query(int i, vi &BIT) {
    int cnt = 0;
    while(i>0) {
        cnt+=BIT[i];
        i -= i&(-i);
    }
    return cnt;
}


int32_t main(){
    fast;
    test() {
        int n; cin>>n; int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];       
        }
        vi BIT(sz+1, 0);
        int total_invcnt = 0;
        for(int i=n-1;i>=0;i--) {
            add(arr[i],BIT);
            total_invcnt+=query(arr[i]-1,BIT);
        }
        cout<<total_invcnt<<endl;
    }
    return 0;
}