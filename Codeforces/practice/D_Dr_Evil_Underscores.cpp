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
int Devil(vector<int>v, int bit) {
    //base case
    if(v.size()==0 or bit<0) return 0;

    //recursive case
    int mask = 1<<bit;
    //segreget in two parts
    vector<int> zeros,ones;
    for(int i=0;i<v.size();i++) {
        if((v[i]&mask)==0) {
            //MSB is 0
            zeros.push_back(v[i]);
        } else {
            //MSB is 1
            ones.push_back(v[i]);
        }
    }

    if(zeros.size()==0) {
        return Devil(ones,bit-1);
    }

    if(ones.size()==0) {
        return Devil(zeros,bit-1);
    }

    return min(Devil(ones,bit-1), Devil(zeros,bit-1))+(1<<bit);
}


#undef int
int main(){
#define int long long 
    fast;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Devil(v,30);
    return 0;
}