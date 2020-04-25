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

void genp(int ope, int clos, int pos,int n, char *s) {
    if(pos==n) {
		s[n] = '\0';
        cout<<s<<endl;
        return;
    }
	if(ope>clos) {
		s[pos] = ')';
		genp(ope,clos+1,pos+1,n,s);
	}
	if(ope<n/2) {
		s[pos] = '(';
		genp(ope+1,clos,pos+1,n,s);
	}
}


#undef int
int main(){
#define int long long 
    fast;
    int n;
    cin>>n;
	char out[2*n];
    genp(0,0,0,2*n,out);
    return 0;
}