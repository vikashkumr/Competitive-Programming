#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
typedef long long ll;
typedef long double ld;
typedef vector<vector<ll> > matrix;
typedef vector<ll> arr;
typedef vector<string> vs;
typedef vector<pair<ll,ll> > pv;
#define in1(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define all(x) x.begin(),x.end()
#define For(i,a,b) for(int i=a;i<=b;++i)
#define rFor(i,a,b) for(int i=a;i>=b;--i)
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

int main(){
    fast;
    string s;
    cin>>s;
    vector<pair<int,int> >zerotwo;
    int sz = s.length();
    string res = "";
    int one = 0;
    rFor(i, sz-1, 0) {
        if(s[i] == '0') {
            res = "0" + res;
        } else if(s[i]=='2') {
            res = "2"+res;
        } else {
            one++;
        }
    }
    int i, zero = 0;
    for(i=0;i<res.length();i++) {
        if(res[i]=='0') {
            zero++;
        } else break;
    }
    int x = 0;
    for(int j=i-1;j>=0;j--) {
        if(one) {
            res[j] = '1';
            one--;
            x++;
        }
    }

    while(one) {
        res = "1" +res;
        one--;
    }

    for(int i=1;i<=x;i++) {
        res="0" + res;
    }
    cout<<res;
    return 0;
}