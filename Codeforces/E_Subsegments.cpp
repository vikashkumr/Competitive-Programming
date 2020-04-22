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
#undef int
int main(){
#define int long long 
    fast;
    int n,k;
    unordered_map<int,int>mp;
    multiset<int, greater<int> >st;
    vector<int>v;
    cin>>n>>k;

    //processing k element initially
    int x = 0;
    int temp;
    cin>>temp;
    v.push_back(temp);
    int lastele = v[x];
    mp[temp]++;
    st.insert(temp);
    for(int i=2;i<=k;i++) {
        cin>>temp;
        mp[temp]++;
        v.push_back(temp);
        if(mp[temp]==1)
        st.insert(temp);
    }
    bool f1 = 0;
    for(auto it : st) {
        if(mp[it]==1) {
            cout<<it<<endl;
            f1 = 1;
            break;
        }
    }
    if(f1 == 0) {
        cout<<"Nothing"<<endl;
    }
    auto it = st.find(lastele);
     mp[lastele]--;
     if(mp[lastele]==0)
    st.erase(it);

    //similar to sliding window concept for k+1 to n element
    FOR(i,1,n){
        //insert
        cin>>temp;
        mp[temp]++;
        if(mp[temp]==1)
        st.insert(temp);
        v.push_back(temp);
        //print
        bool flag = 0;
        for(auto it : st) {
            if(mp[it]==1) {
                cout<<it<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            cout<<"Nothing"<<endl;
        }
        //remove
        auto it = st.find(v[++x]);
        mp[v[x]]--;
        if(mp[v[x]]==0)
        st.erase(it);        
    }
    return 0;
}