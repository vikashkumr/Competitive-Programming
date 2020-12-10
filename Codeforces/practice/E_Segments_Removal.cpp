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
 
struct comp {
    bool operator()(pair<int,int>a, pair<int,int>b) {
        if((a.second-a.first) > (b.second-b.first)) {
            return true;
        } else {
            return a.first<b.first;
        }
    }
};
 
 
int cnt = 0;
#undef int
int main(){
#define int long long 
    fast;
    int n;
    cin>>n;
    int arr[2*n];
    memset(arr,0,sizeof(arr));
    FOR(i,1,n) cin>>arr[i];
    set<pair<int,int>, comp>st;
    map<int,int>l,r;
    
    int strt = 1;
    FOR(i,2,n) {
        if(arr[i]!=arr[i-1]) {
            r[strt] = i-1;
            l[i-1] = strt;
            st.insert({strt,i-1});
            strt = i;
        }
    }
    if(arr[n-1]==arr[n]) {
           r[strt] = n;
           l[n] = strt;
           st.insert({strt,n}); 
    } else {
        r[strt] = n;
        l[n] = strt;
        st.insert({strt,n}); 
    }
 
    while(!st.empty()) {
        cnt++;
        auto it = st.begin();
        pair<int,int> curr = *it;
        st.erase(it);
        arr[curr.first] = -1;
        arr[curr.second] = -1;
        if(st.empty()) break;
        if(curr.first-1>0 and curr.second<=n)
        if(arr[curr.first-1]==arr[curr.second+1] and arr[curr.first-1]!=-1) {
            st.insert({l[curr.first-1],r[curr.second+1]});
            auto it1 = st.find({l[curr.first-1],curr.first-1});
            auto it2 = st.find({curr.second+1,r[curr.second+1]});
            if(it1!=st.end())
            st.erase(it1);
            if(it1!=st.end())
            st.erase(it2);     
        }
    }
    cout<<cnt;
    return 0;
}
→Judgeme