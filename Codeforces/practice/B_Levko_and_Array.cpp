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
//=================================================================//

int arr[2001];
int k,n;
bool isPossible(int x) {
    int dp[2001] = {0};
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(abs(arr[i]-arr[j])<=(i-j)*x) {
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
    }
    int max_transaction = 0;
	for(int i = 0;i<n;i++){
		max_transaction = max(max_transaction,dp[i]);
	}
	int min_transactions = (n-1)-max_transaction; // if there are 5 element and 3 change requiire than it would be better to change 2 element
	return min_transactions <= k;
}


int solve() {
    int s = 0;
    int e = 1e12;
    while(s<=e) {
        int mid = (s+e)/2;
        if(isPossible(mid)) {
            e = mid-1;
        } else {
            s = mid+1;
        }
    }
    return s;
}

int32_t main(){
    fast;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve();
    return 0;
}