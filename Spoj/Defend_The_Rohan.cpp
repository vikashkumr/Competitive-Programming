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
#define pii pair<int,inr>
#define vs vector<string>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//=================================================================//
int A[50][50];
int n;
void floydWarshal() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }   
}
#undef int
int main(){
#define int long long 
    fast;
    int c = 1;
    test() {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
            }
        }
        
        floydWarshal();
        int r;
        cin >> r;
        int sum = 0;
        for (int i = 0; i < r; i++){
            int u, v;
            cin >> u >> v;
            sum += A[--u][--v];
        }
        cout << "Case #" << c << ": " << sum << endl;
        c++;
    }

    return 0;
}