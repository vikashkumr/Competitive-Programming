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

bool isSubs(string &a, string &b) {
    for(int i=0;i<=(b.length()-a.length());i++) {
        if(a == b.substr(i,a.length())) return true;
    }
    return false;
}

int32_t main(){
    fast;
    int n;cin>>n;
    vs v;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        v.push_back(s);       
    }
    sort(all(v), [&](string &a, string &b) -> bool {
        return a.length() < b.length();
    });
    for(int i=1;i<n;i++) {
        if(!isSubs(v[i-1],v[i])) {
            cout<<"NO"<<endl;
            exit(0);
        }
    }
    cout<<"YES"<<endl;
    for(string &a : v) {
        cout<<a<<endl;
    }
    
    return 0;
}