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
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
const int sz = 200006;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//=================================================================//


int32_t main(){
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n+1];
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }


    //outputArr - inputArr = diff array

    int l[sz] = {0}, r[sz] = {0}, d[sz] = {0}, diff[sz] = {0}, cnt[sz] = {0};
    for (int i = 1; i <= m; i++){
        cin >> l[i] >> r[i] >> d[i];
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y + 1]--;
    }
    //prefix sum array of count how many times each operations occur
    for (int i = 1; i <= m;i++) {
        cnt[i] += cnt[i - 1];
    }
    
    //going to each operation
    for (int i = 1; i <= m;i++) {
        diff[l[i]] += cnt[i] * d[i];
        diff[r[i] + 1] -= cnt[i] * d[i];
    }

    for (int i = 1; i <= n; i++) {
        arr[i] += (diff[i] += diff[i - 1]);
    }
    
    for (int i = 1; i <= n; i++){
        cout << arr[i]<<" ";
    }
    return 0;
}