#include<iostream>
using namespace std;
string charFormat(string s,int size){
	if(size==0)
	return s;
	if(s[size]==s[size-1]){
		s.insert(size,"*");
		return charFormat(s,size-1);
	}
	else
	return charFormat(s,size-1);
}
int main(){
	string s;
	cin>>s;
	s=charFormat(s,s.length()-1);
	cout<<s;
	return 0;
}
