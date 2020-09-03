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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];       
    }
    unordered_map<int,int> hm;
    int cnt = 0;
    vp vpair;
    int last_idx = 0;
    for(int i=0;i<n;i++) {
        if(hm[arr[i]] != 0) {
            vpair.push_back({last_idx+1, i+1});
            hm.clear();
            last_idx = i+1;
        } else
        hm[arr[i]]++;
    }
    if(vpair.size() == 0) cout<<-1;
    else {
        int i=0;
        cout<<vpair.size()<<endl;
        for(auto x : vpair) {
            if(i==vpair.size()-1) {
               cout<<x.first<< " "<<n; 
               break;   
            }
            cout<<x.first<< " "<<x.second<<endl;
            i++;
        }
    }
    return 0;
}