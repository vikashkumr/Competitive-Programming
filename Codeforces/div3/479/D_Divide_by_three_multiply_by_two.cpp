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
vi res;
bool ok = 0;
void solve(int curr, vi &a, vi tmp, unordered_map<int,int> hm) {
    if(ok) return;
    if(tmp.size() == a.size()) {
        ok = 1;
        res = tmp;
        return;
    }

    if(curr%3==0 && hm[curr/3]>0) {
        tmp.push_back(curr/3);
        hm[curr/3]--;
        solve(curr/3, a, tmp, hm);
        tmp.pop_back();
        hm[curr/3]++;
    }
    if(hm[2*curr]>0) {
        tmp.push_back(2*curr);
        hm[2*curr]--;
        solve(2*curr, a, tmp, hm);
        tmp.pop_back();
        hm[2*curr]++;
    }

}


int32_t main(){
    fast;
    int n;cin>>n;
    vi a(n);
    unordered_map<int,int> hm;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        hm[a[i]]++;       
    }
    for(int i=0;i<n;i++) {
        if(!ok) {
            vi tmp;
            solve(a[i],a, tmp, hm);
        } else break;
    }
    for(int x: res) cout<<x<<endl;
    return 0;
}