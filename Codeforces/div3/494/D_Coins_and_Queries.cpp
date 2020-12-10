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
    int n,q;
    cin>>n>>q;
    unordered_map<int,int> hm;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        hm[tmp]++;       
    }

    while(q--) {
        int x, cnt = 0;
        cin>>x;
        for(int i=31;i>=0;i--) {
            if((1<<i) <= x && hm[(1<<i)]>0) {
                int fre = hm[(1<<i)];
                int times =  x / (1<<i);
                cnt+=min(times,fre);
                x-=min(times,fre)*(1<<i);
            }
        }
        if(x==0) cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
    
    return 0;
}