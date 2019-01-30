#include<bits/stdc++.h>
using namespace std;
int main()
{
	int p,s;
	cin>>p>>s;
	vector<pair<int,int> >v1;
	for(int j=1;j<=p;j++)
	{
		vector<pair<int,int> >v;
		int arr[s],count=0;
		for(int i=0;i<s;i++)
		cin>>arr[i];
		for(int i=0;i<s;i++)
		{
			int x;
			cin>>x;
			v.push_back({arr[i],x});
		}
		sort(v.begin(),v.end());
		for(int i=0;i<s-1;i++)
		if(v[i].second>v[i+1].second)
		count++;
		v1.push_back({count,j});
	}
	sort(v1.begin(),v1.end());
	for(int i=0;i<v1.size();i++)
	 cout<<v1[i].second<<endl;
	return 0;
}