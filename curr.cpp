#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define L_MAX 1e18
#define ll  long long
using matrix = vector<vector<ll>>;

vector<ll>temp;
matrix d;
set<char>c;
string a,b;
ll n;

void print() {
    cout<<(int)d.size()<<endl;
    for(auto i : d){
        cout<<i.size()<<" ";
        for(auto k : i)
            cout<<k<<" ";
        cout<<endl;
    }
}

void solve() {
    for(auto i=c.rbegin();i!=c.rend();i++){
        ll c=0;
        for(int po=0;po<n;po++){
            if(b[po]==*i or a[po]==*i){
                if(a[po]>=*i){
                    if(a[po]==*i)
                        c++;
                    temp.pb(po);
                    a[po]=*i;
                }
            }
        }
        if(c!=(int)temp.size())
            d.push_back(temp);
    }
    if(a==b){
        print();
    }else{
        cout<<-1<<endl;
    }
}



int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b;
        map<char,ll>x;
        for(auto i : a){
            x[i]++;
        }
        ll ok=1;
        
        for(auto i : b){
            ok&=(x[i]>0);
            c.insert(i);
        }
        if(!ok){
            cout<<-1<<endl;
        } else {
            solve();
        }
    }
    return 0;
}