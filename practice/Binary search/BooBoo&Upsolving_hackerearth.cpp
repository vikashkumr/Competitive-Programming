//binar search
//©vikash
#include<iostream>
#define ll long long
using namespace std;
bool poss(ll arr[],ll arrsize,ll time,ll days){
	ll sum=0,d=0;
	for(ll i=0;i<arrsize;i++){
		sum+=arr[i];
		if(sum==time){
			d++;
			sum=0;
		}
		if(sum>time){
			d++;
			sum=0;
			i--;
		}
	}
	//if some elements left out
	if(sum)
	d++;
	if(d<=days)
	return 1;
	return 0;
	
	
	
}
int main(){
	
	ll n,m,mx=0,sum=0;
	cin>>n>>m;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		mx=max(mx,arr[i]);
	}
	ll l=mx,r=sum,ans=0;
	while(l<r){
		ll mid=l+(r-l)/2;
		if(poss(arr,n,mid,m)){
			//ans=mid;
			r=mid;
		}
		else
		l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}
