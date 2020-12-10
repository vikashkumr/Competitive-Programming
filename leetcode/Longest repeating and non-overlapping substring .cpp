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

//GFG-variation of Longest common Substring
int32_t main(){
    fast;
    test() {
        string s1,s2;
        int l1, l2;
        cin>>l1;
        cin>>s1;
        l2 = l1;
        s2 = s1; 
        int ans = -1;
        int dp[l1][l2]={0};
        int idx = 0;
        for(int i=1;i<l2;i++) if(s2[i] == s1[0]) dp[0][i] = 1, ans = 1, idx = i; else dp[0][i] = 0;
        for(int i=1;i<l1;i++) {
            for(int j=i+1;j<l2;j++) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > ans) {
                        ans = dp[i][j];
                        idx = j;
                    }
                } 
            }
        }
        if(ans == -1) cout<<-1<<endl;
        else {
            idx = idx-ans+1;
            while(ans--) {
                cout<<s1[idx++];
            }   
            cout<<endl;
        }
    }  
    return 0;
}