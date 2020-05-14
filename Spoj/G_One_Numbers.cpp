#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
typedef long double ld;
typedef vector<vector<int> > matrix;
typedef vector<int> arr;
typedef vector<string> vs;
typedef vector<pair<int,int> > pv;
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};
//=================================================================//
int dp[10][81][2];
int a,b;
string s;
int ar[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79};
bool present(int n) {
    for(int i=0;i<=21;i++) {
        if(ar[i]==n) return true;
    }
    return false;
}

int solve(int pos,int sum, int tight) {
    if(pos==s.length()) return present(sum);

    int &ans = dp[pos][sum][tight];
    if(ans != -1) return ans;

    int res = 0;
    int end = (tight) ? (s[pos]-'0') : 9;
    for(int i=0; i<=end; i++) {
        res += solve(pos+1,sum+i, tight&(i==end));
    }

    return ans = res;
}


#undef int
int main(){
#define int long long 
    fast;
    int t;
    cin>>t;
    while(t--) {
         cin>>a>>b;
        memset(dp, -1, sizeof dp);
        s = to_string(b);
        int ansr = solve(0,0,1);
        memset(dp, -1, sizeof dp);
        a -= 1;
        s = to_string(a);
        int ansl = solve(0,0,1);
        cout<<ansr-ansl<<endl;
    }
    return 0;
}