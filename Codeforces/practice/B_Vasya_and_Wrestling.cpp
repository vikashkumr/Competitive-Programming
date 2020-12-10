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
#define FOR(i,a,b) for(int i=a;i<=b;--i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};

int main(){
    fast;
    int n;
    cin>>n;
    ll first = 0, second = 0;
    bool flag = false;
    int fc = 0,sc = 0;
    ll temp;
    arr a1,a2;
    for(int i=0;i<n;i++) {
        cin>>temp;
        if(i==n-1 and temp<0) flag = true;
        if(temp>0) {
            first+=temp;
            fc++;
            a1.pb(temp);
        }
        else {
            second+=abs(temp);
            a2.pb(abs(temp));
            sc++;
        }
        
    }
    if(first>second) {
        cout<<"first"<<endl;
    } else if(second>first) {
        cout<<"second"<<endl;
    } else if(fc>sc){
        bool t = 0;
        for(int i=0;i<a2.size();i++) {
            if(a1[i]>a2[i])  {
                cout<<"first";
                t = 1;
                break;
            } else if(a1[i]<a2[i]){
                cout<<"second";
                t = 1;
                break;
            }
        }
        if(t==0) cout<<"first";
    } else if(sc>fc){
        bool t = 0;
        for(int i=0;i<a1.size();i++) {
            if(a1[i]>a2[i])  {
                cout<<"first";
                t = 1;
                break;
            } else if(a1[i]<a2[i]){
                cout<<"second";
                t = 1;
                break;
            }
        }
        if(t==0) cout<<"second";
    } else if(sc==fc) {
         bool t = 0;
        for(int i=0;i<a1.size();i++) {
            if(a1[i]>a2[i])  {
                cout<<"first";
                t = 1;
                break;
            } else if(a1[i]<a2[i]){
                cout<<"second";
                t = 1;
                break;
            }
        }
        if(t==0){
           if(flag) cout<<"second"<<endl;
            else cout<<"first"<<endl; 
        }
    }
    
    
    
    
    return 0;
}