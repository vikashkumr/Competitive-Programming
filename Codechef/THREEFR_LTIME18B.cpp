#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if((x+y-z==0) || (z+y-x==0) || (z+x-y==0))
		cout<<"yes\n";
		else
		cout<<"no\n";
	}
	return 0;
}