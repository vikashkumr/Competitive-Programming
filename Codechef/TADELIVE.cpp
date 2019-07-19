#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,x,y,sum=0;
    cin>>n>>x>>y;
    ll Andy[n],Bob[n];
    for(int i=0;i<n;i++)
    cin>>Andy[i];
    for(int i=0;i<n;i++)
    cin>>Bob[i];
    vector<pair<ll,pair<ll,ll> > >vp;
    for(int i=0;i<n;i++){
        vp.push_back(make_pair(abs(Andy[i]-Bob[i]),make_pair(Andy[i],Bob[i])));
    }
    sort(vp.rbegin(),vp.rend());
    int Xcount = 0;
    int Ycount = 0;
    for(int i=0;i<n;i++){
        ll a = vp[i].second.first;
        ll b = vp[i].second.second;
        if(a>b){
            if(Xcount<x){
                sum+=a;
                Xcount++;
            }
            else {
                sum+=b;
                Ycount++;
            }
        }
        else {
            if(Ycount<y){
                sum+=b;
                Ycount++;
            }
            else {
                sum+=a;
                Xcount++;
            }
        }
    }
    cout<<sum<<"\n";
    return 0;
}