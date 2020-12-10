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
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];       
    }
    int i = 0, j = n-1;
    int cnt = 0;
    while(i<=j) {
        if(a[i] <= k) cnt++, i++;
        else if(a[j] <= k) cnt++, j--;
        else break;
    }
    cout<<cnt<<endl;
    
    return 0;
}