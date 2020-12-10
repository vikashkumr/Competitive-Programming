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
    string s1,s2;
    cin>>s1>>s2;
    int ans = 0;
    for(int i=0;i<(n+1)/2;i++) {
        if((n&1) and i==n/2) {
            if(s1[i]!=s2[i]) ans++;
            break;
        }
        unordered_map<char,int> hm;
        hm[s1[i]]++;
        hm[s1[n-i-1]]++;
        hm[s2[i]]++;
        hm[s2[n-i-1]]++;
        if(hm.size()==4) ans+=2;
        else if(hm.size()==2) {
            ans+=hm[s1[i]]!=2;
        } else if(hm.size()==3){
            ans+=1+(s1[i]==s1[n-i-1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}