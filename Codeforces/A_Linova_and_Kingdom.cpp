#include<bits/stdc++.h>
using namespace std;
 
vector<int> v[200005];
priority_queue<int>pq;
int dfs(int x,int p,int d){
	int l=0;
	for(auto y:v[x]){
		if(y==p)continue;
		l+=dfs(y,x,d+1);
	}
	pq.push(d-l);
	return l+1;
}
 
int main(){
	int n,k,i,x,y;
	long long a=0;
    cin >> n >> k;
    for (i = 1; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    dfs(1,0,0);
	long long sum = 0;
    while(k--) {
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
	return 0;
}