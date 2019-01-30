#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int answer,l,temp,count=0,number=0,c=0;
	string s;
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++)
		{
			if(s[i]=='.')
			break;
			else 
			c++;
		}
		if(c==l)
		printf("1\n");
		else
		{
	for(int i=l-1;s[i]!='.';i--)
	{
			count++;
	}
    for(int i=0;i<l;i++)
    {
    	if(s[i]=='.')
    	continue;
    	else
    	number=number*10+(s[i]-'0');
	}
	temp=gcd(number,pow(10,count));
	answer=pow(10,count)/temp;
	cout<<answer<<"\n";
}}
	return 0;
}
