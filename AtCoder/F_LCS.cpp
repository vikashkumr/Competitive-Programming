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

int dp[3001][3001];
void longestCommonSubsequence(string A, string B) {
    
    memset(dp, -1, sizeof dp);
    for(int i=0;i<=A.length();i++) dp[i][0] = 0;
    for(int i=0;i<=B.length();i++) dp[0][i] = 0;
    for(int i=1;i<=A.length();i++) {
        for(int j=1;j<=B.length();j++) {
            if(A[i-1]==B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }    
}

#undef int
int main(){
#define int long long 
    fast;
    string s1, s2;
    cin>>s1>>s2;
    longestCommonSubsequence(s1,s2);
    int i = s1.length(), j = s2.length();
    string res = "";
    while(i!=0 and j!=0) {
        if(s1[i-1]==s2[j-1]) {
            res+=s1[i-1];
            i--;j--;
        } else {
            if(dp[i][j-1]>dp[i-1][j]) {
                j--;
            } else i--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<res;
    return 0;
}