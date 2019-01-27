#include<bits/stdc++.h>
using namespace std;
int sumOfDigit(string s,int n,int ans){
	if(n==-1){
	return s[0]-'0';
	//return ans;	
	}
	return ans+sumOfDigit(s,n-1,s[n]-'0');
}
int main(){
	string s;
	cin>>s;
	cout<<sumOfDigit(s,s.length()-1,0);
	return 0;
}
