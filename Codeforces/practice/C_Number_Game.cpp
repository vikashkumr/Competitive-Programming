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
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int sz = 100005;
//=================================================================//
bool prime(int n) {
    if (n<2) return false;
    if (n<=3) return true;
    if (!(n%2) || !(n%3)) return false;
    for (int i=5;i*i<=n;i+=6)
        if (!(n%i) || !(n%(i+2))) return false;
    return true;
}

int32_t main(){
    fast;
    test() {
        int n;
        cin>>n;
        if(n==1 || (!(n&(n-1)) && n>2) || (!(n&1) and prime(n/2))) cout<<"FastestFinger"<<endl;
        else cout<<"Ashishgup"<<endl;
    }
    return 0;
}