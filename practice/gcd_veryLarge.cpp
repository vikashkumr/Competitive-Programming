//gcd if one of th number is very large
//©vikash
#include<iostream>
#include<cstring>
using namespace std;
int gcd(int x,int y){
	if(y==0)
	return x;
	return gcd(y,x%y);
}
int main(){
	int y,ans;
	string x;
	cin>>x>>y;
	for(int i=0;i<x.length();i++){
		ans=(ans*10+(x[i]-'0'))%y;
	}
	ans%=y;
	cout<<gcd(y,ans);
	return 0;
}
