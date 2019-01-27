#include<iostream>
using namespace std;
string removeDupli(string s,int size){
	if(size==0)
	return s;
	if(s[size]==s[size-1]){
		s.erase(size,1);
		return removeDupli(s,size-1);
	}
	else
	return removeDupli(s,size-1);
}
int main(){
	string s;
	cin>>s;
	s=removeDupli(s,s.length()-1);
	cout<<s;
	return 0;
}
