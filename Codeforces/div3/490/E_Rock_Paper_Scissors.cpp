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
    vector<int> a(3), b(3);
    for(int i=0;i<3;i++) cin>>a[i];
    for(int i=0;i<3;i++) cin>>b[i];
    int mx = 0,mn = INT_MAX;
    vp order;
    order.pb({0, 0});
	order.pb({0, 2});
	order.pb({1, 1});
	order.pb({1, 0});
	order.pb({2, 2});
	order.pb({2, 1});
    sort(all(order));
    do {
        vector<int> a1 = a, b1 = b;
        for(int i=0;i<6;i++) {
            int cnt = min(a1[order[i].first], b1[order[i].second]);
            a1[order[i].first] -= cnt;
            b1[order[i].second] -= cnt;
        }
        int cur = min(a1[0], b1[1]) + min(a1[1], b1[2]) + min(a1[2], b1[0]);
        mn = min(mn,cur);
    } while(next_permutation(all(order)));
    mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    cout<<mn<<" "<<mx<<endl;
    return 0;
}