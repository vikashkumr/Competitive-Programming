#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

ll func(long long int arr[], ll x,ll n){
ll ans = 0;
for(ll i =0;i<n;i++)
    {
        ll k=(arr[i]-x);
        if(k>0)
        ans+=k;
    }
return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    ll n,m,sum=0,mid,max=-1;
    cin>>n>>m;
    ll v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>max)
        max=v[i];
    }
    
    ll left = 0, right = max;
    while(right-left>1){
        
        mid = left+(right-left)/2;
        sum=func(v,mid,n);
        
        if(sum==m){
        cout<<mid;
        exit(0);
        }
        
        if(sum>m)
        left = mid;
        else if(sum<m)
        right = mid-1;
    }
   if(func(v,right,n)>=m)
    {
        cout<<right;
        exit(0);
    }
    else if(func(v,left,n)>=m){
        cout<<left;
        exit(0);
    }
    else{
        cout<<-1;
        exit(0);
    }
    return 0;
}