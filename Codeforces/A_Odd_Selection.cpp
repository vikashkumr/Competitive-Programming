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
#define vs vector<string>
#define vp vector<pair<int,int> >
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};
//=================================================================//


#undef int
int main(){
#define int long long 
    fast;
    test() {
        int n, x, tmp, even = 0, odd = 0;
        cin >> n >> x;
        for (int i = 0; i < n;i++) {
            cin >> tmp;
            if(tmp&1) odd++;
            else even++;
        }
        if(odd == 0)
            cout << "NO"<<endl;
        else {
            bool ok = 1;
            for (int i = 1; i <= min(odd,x); i += 2)
            {
                if(even>=x-i) {
                    cout << "YES" << endl;
                    ok = 0;
                    break;
                }
            }
            if(ok)
                cout << "NO" << endl;
        }
    }

    return 0;
}