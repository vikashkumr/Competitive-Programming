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
    int n; cin>>n;
    unordered_set<int> st;
    st.insert(0);
    int ans = 0, pre_sum = 0;
    for(int i=0;i<n;i++) {
        int tmp; cin>>tmp;
        pre_sum+=tmp;
        if(st.find(pre_sum)!=st.end()) {
            ans++;
            st.clear();
            st.insert(0);
            pre_sum = tmp;
        }   
        st.insert(pre_sum);
    }
    cout<<ans<<endl;
    return 0;
}