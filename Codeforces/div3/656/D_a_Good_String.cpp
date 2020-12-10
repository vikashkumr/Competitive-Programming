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

int cnt(int st, int end, string &s, char ch) {
    int res = 0;
    for(int i=st;i<=end;i++) {
        if(s[i]!=ch) res++;
    }
    return res;
}

int solve(string &s, char ch, int sz, int st, int end) {
    if(sz==0) {
        if(s[st]==ch) return 0;
        return 1;
    }
    int op1 = cnt(st, (end+st)/2, s, ch) + solve(s, ch+1, sz/2, (end+st)/2+1, end); 
    int op2 = cnt((end+st)/2 + 1, end, s, ch) + solve(s, ch+1, sz/2, st, (end+st)/2);

    return min(op1, op2); 
}

int32_t main(){
    fast;
    test() {
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(s, 'a', n/2, 0, n-1)<<endl;
    }
    
    return 0;
}