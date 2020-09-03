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

int dp[102][102][2];
int solve(int m, int pos, int turn, vector<int> &piles) {
    //base case
    if(pos >= piles.size()) return 0;
    //recursive case
    int n = piles.size()-1;
    int &res = dp[m][pos][turn];
    if(res != -1) return res;
    if(turn) {
        int sum = 0;
        int ans = INT_MIN;
        for(int i=pos;i<pos+2*m;i++) {
            if(i<=n) {
                sum+=piles[i];
                ans = max(ans, sum + solve(max(m,i-pos+1), i+1, 0, piles)); 
            }
        }
        return res = ans;
    }
    else {
        int ans = INT_MAX;
        for(int i=pos;i<pos+2*m;i++) {
            if(i<=n)
            ans = min(ans, solve(max(m,i-pos+1), i+1, 1, piles));
        }
        return res = ans;
    }
}

int stoneGameII(vector<int>& piles) {
    piles.insert(piles.begin(), 1, 0);
    memset(dp, -1, sizeof dp);
    return solve(1, 1, 1, piles);
}

int32_t main(){
    fast;
    test() {
        int n;
        vector<int> piles;
        for(int i=0;i<n;i++) {
            int tmp;
            cin>>tmp;
            piles.push_back(tmp);       
        }
        int score = stoneGameII(tmp)
    }
    
    return 0;
}
