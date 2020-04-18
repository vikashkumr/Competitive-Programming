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
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

//=================================================================//
int cnt = 0;
void printAscii(string str, string res, int idx,int n) {
    if(idx==n) {
		cnt++;
        cout<<res<<" ";
        return;
    }
	//nahi rkhna hai
    printAscii(str,res,idx+1, n);

    //rakhna hai
    printAscii(str,res+str[idx],idx+1, n);

	//ASCII
	printAscii(str,res+to_string((int)str[idx]),idx+1, n);

}

int main(){
    fast;
    string s;
    cin>>s;
    printAscii(s, "", 0, s.length()); 
	cout<<endl; 
	cout<<cnt;
    return 0;
}