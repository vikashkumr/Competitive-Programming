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
map<int,int> mp;
void p_factor(int n){
    int cnt = 0;
    bool ok = 0;
    while (n % 2 == 0) { 
		cnt++;
		n = n/2; 
        ok = 1;
	} 

    if(ok) mp[2] = cnt, cnt = 0;
    for (int i = 3; i <= (long)sqrtl(n); i = i + 2) {
        ok = 0;
		while (n % i == 0) { 
            ok = 1;
			cnt++;
			n = n/i; 
		} 
        if(ok) {
            mp[i] = i;
            cnt = 0;
        }
	} 
    if(n>2) {
        mp[n] = 1;
    }
    mp[1] = 1;

}

int32_t main(){
    fast;
    test() {
        int n;cin>>n;
        p_factor(n);
        int mx = INT_MIN;
        int ele = 1;
        for(auto it: mp) {
            if(it.second > mx) mx = it.second, ele = it.first;
        }
        for(int i=1;i<mx;i++) cout<<ele<<" ";
        cout<<n/ele<<endl;
    }    
    return 0;
}