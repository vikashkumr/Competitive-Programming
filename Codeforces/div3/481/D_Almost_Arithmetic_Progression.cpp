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
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
const int sz = 100005;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//
int dx[] = {0, 0, 0, -1, -1, -1, 1, 1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, 0, -1, 1};

int32_t main(){
    fast;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];       
    }
    int final_ans = INT_MAX;
    if(n<=2) {
        cout<<0<<endl;
        exit(0);
    } else {
        for(int j=0;j<9;j++) {
            int d = a[0]+dx[j]-(a[1]+dy[j]);
            int tmp[n];
            for(int k=0;k<n;k++) {
                tmp[k] = a[k];       
            }
            tmp[1] = a[1]+dy[j];
            int cur_ans = abs(dx[j]) + abs(dy[j]);
            bool flag = 0;
            for(int i=2;i<n;i++) {
                if(tmp[i-1]-tmp[i]==d) ;
                else if((tmp[i-1]-(tmp[i]+1))==d) {
                    cur_ans++;
                    tmp[i]++;
                } else if((tmp[i-1]-(tmp[i]-1))==d) {
                    cur_ans++;
                    tmp[i]--;
                } else{
                    break;
                }
                if(i==n-1) flag = 1;
            }
            if(flag)
            final_ans = min(final_ans, cur_ans);
        }
    }
    if(final_ans==INT_MAX) cout<<-1<<endl;
    else cout<<final_ans<<endl;
    
    return 0;
}
