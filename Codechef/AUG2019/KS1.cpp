#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll countValue(vector<ll>&v){
    ll count=0;
    ll size = v.size();
    ll sum[size];
    sum[0]=v[0];
    for(int i=1;i<size;i++)
    sum[i]=sum[i-1]+v[i];
    for(int i=1;i<size;i++)
    count+=v[i]*i-sum[i-1]-i;
    return count;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,temp,count=0;
        cin>>n;
        unordered_map<ll,vector<ll> >mp;
        ll preFix[n];
        cin>>preFix[0];
        mp[preFix[0]].push_back(0);
        for(ll i=1;i<n;i++){
            cin>>temp;
            preFix[i]=preFix[i-1]^temp;
            if(preFix[i]==0){
            	count+=i;
            	mp[preFix[i]].push_back(i);
            }
            else
            mp[preFix[i]].push_back(i);
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second.size()>1)
            count+=countValue(it->second);
        }
        cout<<count<<"\n";
    }
    return 0;
}
