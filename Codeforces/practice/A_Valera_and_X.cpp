#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef vector<vector<ll> > matrix;
typedef vector<ll> arr;
typedef vector<string> vs;
typedef vector<pair<ll,ll> > pv;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

char box[300][300];

bool check(char xchar, char othchar, int n) {
    if(xchar == othchar) return false;
    FOR(i,0,n-1) {
        if(box[i][i]!=xchar or box[i][n-i-1]!=xchar) return false;
        FOR(j,0,n-1) {
            if(j!=i and j!=(n-i-1)) {
                if(box[i][j]!=othchar) return false;
            }
        }
    }
    return true;
}

int main(){
    fast;
    int n;
    cin>>n;
    char ch;
    FOR(i,0,n-1) {
       cin>>box[i];
    }
    char xchar = box[0][0];
    char otherchar = box[0][1];
    check(xchar, otherchar, n) ? cout<<"YES" : cout<<"NO";
    return 0;
}