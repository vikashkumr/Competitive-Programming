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
map<int,int> eletoidx;
#undef int
int main(){
#define int long long 
    fast;
    int n;
    eletoidx[4] = 1;
    eletoidx[8] = 2;
    eletoidx[15] = 3;
    eletoidx[16] = 4;
    eletoidx[23] = 5;
    eletoidx[42] = 6;
    cin>>n;
    int bound = n/6;
    if(n<6) cout<<n,exit(0);
    int arr[7] = {0};
    int ans = 0;
    int in;
    FOR(i,1,n) {
        cin>>in;
        if(eletoidx[in]==0) ans++;
        else {
            if(in==42) {
                int cnt = 0;;
                for(int i=5;i>=1;i--) {
                    if(arr[i]>=arr[6]+1) {
                        cnt++;
                    }
                }
                if(cnt==5) {
                   for(int i=5;i>=1;i--) arr[i]--;       
                } else ans++;   
            }
            else if(in==4){
                if(arr[1]==bound) ans++;
                else arr[1]++;
            } else {
                if(arr[eletoidx[in]]>=bound) {ans++;continue;}
                int cnt = 0;
                for(int i = eletoidx[in]-1;i>=1;i--){
                    if(arr[i]==0) break;
                    if(arr[i]<=bound and arr[i]>=arr[eletoidx[in]]+1) cnt++;
                }
                if(cnt==eletoidx[in]-1) {
                    arr[eletoidx[in]]++;
                } else ans++;
            }
            
        }
    }
    for(int i=1;i<=6;i++) ans+=arr[i];
    cout<<ans;
    return 0;
}