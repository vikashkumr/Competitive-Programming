// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/entrance-examination-01e4a1b9/description/

#include <bits/stdc++.h>
using namespace std;
bool hm[4000006];
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,a,b;
		cin>>n>>a>>b;
		// unordered_map<int,bool> hm;
		int s = n*b;
		int d=n*a+s;
		queue<pair<int,int>>q;
		q.push({s,0});
		memset(hm, 0, sizeof hm);
		hm[s] = 1;
		int ans = 0;
		while(!q.empty()) {
			int lvl = q.front().second;
			int tmp = q.front().first;
			q.pop();
			if(lvl>=n) continue;
			if(tmp+a<=d and !hm[tmp+a]) {
                q.push({tmp+a,lvl+1});
                hm[tmp+a] = 1;
			}
			if(tmp-b>=0 and !hm[tmp-b]) {
                q.push({tmp-b,lvl+1});
                hm[tmp-b] = 1;
			}
		}
		for(int i = 0;i<=d;i++) {
            ans+=hm[i];
		}
		cout<<ans<<endl;
	}
}

