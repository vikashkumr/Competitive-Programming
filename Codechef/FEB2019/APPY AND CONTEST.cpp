#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll comn,n,a,b,k,ans,c1,lcm;
		cin>>n>>a>>b>>k;
		ll a1=n/a,b1=n/b;
		lcm=(a*b)/gcd(a,b);
		c1=n/lcm;
		ans=a1+b1-2*c1;
		if(ans>=k)
		cout<<"Win"<<"\n";
		else
		cout<<"Lose"<<"\n";
	}	
return 0;
}
