#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,temp=0;
		cin>>n>>m;
		string grid[n];
		for(int i=0;i<n;i++)
		cin>>grid[i];
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<m;j++)
			{
				if((grid[i][j]=='.' || grid[i][j]=='*') && (grid[i][j+1]=='.' || grid[i][j+1]=='*') && (grid[i+1][j]=='.' || grid[i+1][j]=='*') && (grid[i+1][j+1]=='.' || grid[i+1][j+1]=='*'))
				{
					grid[i][j]='*';
					grid[i][j+1]='*';
					grid[i+1][j]='*';
					grid[i+1][j+1]='*';
				}
				else
				continue;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			if(grid[i][j]=='*' || grid[i][j]=='#')
			temp++;
		}
		if(temp==n*m)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}