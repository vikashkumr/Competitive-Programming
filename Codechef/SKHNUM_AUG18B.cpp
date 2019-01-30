#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sOT[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll N;
		ll i=0;
		cin>>N;
		while(sOT[i]<=N)
		i++;
		i=i-1;
		for(ll j=0;j<=i;j++)
		{
			if(sOT[i]+sOT[j]>=N)
			{
				if(N==1)
				cout<<2<<endl;
				else if(j==0)
				cout<<sOT[i]+sOT[j]-N<<"\n";
				else if(j==i)
				cout<<min((N-(sOT[i]+sOT[j-1])),(1+sOT[i]+sOT[j]-N))<<"\n";
				else
				cout<<min((sOT[i]+sOT[j]-N),(N-(sOT[i]+sOT[j-1])))<<"\n";
				break;
			}
		}
	}
	return 0;
}