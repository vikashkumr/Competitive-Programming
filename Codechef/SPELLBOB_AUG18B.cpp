#include<iostream>
using namespace std;
string bob(string s1,string s2)
{
	if((s1[0]=='b' || s2[0]=='b') && (s1[1]=='o' || s2[1]=='o') && (s1[2]=='b' || s2[2]=='b'))
	return "yes";
	if((s1[0]=='o' || s2[0]=='o') && (s1[1]=='b' || s2[1]=='b') && (s1[2]=='b' || s2[2]=='b'))
	return "yes";
	if((s1[0]=='b' || s2[0]=='b') && (s1[1]=='b' || s2[1]=='b') && (s1[2]=='o' || s2[2]=='o'))
	return "yes";
	return "no";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s1,s2;
	cin>>s1>>s2;
	cout<<bob(s1,s2)<<endl;
    }
	return 0;
}