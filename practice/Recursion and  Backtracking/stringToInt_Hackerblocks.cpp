#include<bits/stdc++.h>
#include<string>
using namespace std;
string replace(string s,int i,int n){
	string s1,s2,ss,sans=s;
	if(i>=n-2)
	{
		cout<<sans;
		return "";
	}
	ss=s.substr(i,i+2);
	if(ss=="pi"){
		s1=s.substr(0,i);
		s2=s.substr(i+2);
		sans=s1+"3.14"+s2;
		return replace(s,i+2,n);
		//return;
	}
	else
	return replace(s,i+1,n);
}
int main(){
	string s;
	cin>>s;
	int l=s.length();
	replace(s,0,l);
	return 0;
}
