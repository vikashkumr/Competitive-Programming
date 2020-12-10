// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem/0

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
    test() {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int k;
        cin>>k;
        for(int i=0;i<n;i++) a[i]%=k;
        unordered_map<int,int> hm;
        for(int i=0;i<n;i++) hm[a[i]]++;
        int cnt = 0, ans = 0;
        for(int i=0;i<n;i++) {
            if(a[i]==0) {
                ans++;
                continue;
            }
            if(hm[k-a[i]]>0) {
                cnt++;
                hm[a[i]]--;
                hm[k-a[i]]--;
            }
        }
        cnt+=(ans/2);
        if(n&1) cout<<"False"<<endl;
        else if(cnt==n/2) cout<<"True"<<endl;
        else cout<<"False"<<endl;
    }
    
    return 0;
}