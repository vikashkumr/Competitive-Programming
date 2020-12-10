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
const int sz = 250;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//

int cnt[sz];
int32_t main(){
    fast;
    int n,k;cin>>n>>k;
    vp v(n);
    vi ans(n);
    for(int i=0;i<n;i++) {
        cin>>v[i].first>>v[i].second; 
        cnt[v[i].first]++;
        cnt[v[i].second+1]--;  
    }
    for(int i=1;i<sz-1;i++) cnt[i]+=cnt[i-1];
    
    for(int i=0;i<sz;i++) {
        while(cnt[i] > k) {
            int pos = -1;
			for (int p = 0; p < n; ++p) {
				if (!ans[p] && (v[p].first <= i && i <= v[p].second) && (pos == -1 || v[p].second > v[pos].second)) {
					pos = p;
				}
			}
            for (int j = v[pos].first; j <= v[pos].second; ++j) {
				--cnt[j];
			}
			ans[pos] = 1;
        }
    }
    cout << accumulate(ans.begin(), ans.end(), 0) << endl;
	for (int i = 0; i < n; ++i) {
		if (ans[i]) cout << i + 1 << " ";
	}   
    return 0;
}