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
    int n;cin>>n;
    vector<pair<int,pair<int,int>>> p;
    for(int i=0;i<n;i++) {
        int k;cin>>k;
        vector<int> x(k);
        for(int j=0;j<k;j++) {
            cin>>x[j];
        }
        int sum = accumulate(all(x), 0);
        for(int j=0;j<k;j++) {
            p.push_back({sum-x[j],{i+1, j+1}});
        }
    }
    sort(all(p));
    for(int i=1;i<p.size();i++) {
        if(p[i].first == p[i-1].first) {
            cout<<"YES"<<endl;
            cout<<p[i].second.first<<" "<<p[i].second.second<<endl;
            cout<<p[i-1].second.first<<" "<<p[i-1].second.second<<endl;
            exit(0);
        }
    }
    cout<<"NO"<<endl;
    return 0;
}