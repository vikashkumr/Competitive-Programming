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

int divisor(int n) {
    int ans = 0;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) ans++;
    }
    if(((int)sqrtl(n) * (int)sqrtl(n)) == n) return (2*ans)-1;
    return 2*ans;
}

int32_t main(){
    fast;
    int n, k;
    cin>>n>>k;
    int no = divisor(n);
    if(k>no) {
        cout<<-1;
        exit(0);
    }
    int div = 0;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0){
            div++;
            if(div==k || no-div+1==k) {
                if(div==k) {
                    cout<<i;
                    break;
                } else {
                    cout<<n/i;
                    break;
                }
            }
        }
    }
    
    return 0;
}