//BFS
// reduse n to 1 using 3 operaton any number of times n/3 or n/2 or n-1
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int>v; unordered_set<int>s;
		int ans = 0;
		bool found = 0;
		if(n==1) found = 1;
		int cs = 1;  //current size of vector
		v.push_back(n);
		int i = 0;
		while(!found) {
			ans++;
			for(i;i<cs;i++) {
				int first = -1, sec = -1, thi = -1;
				if(v[i]%3==0) first = v[i]/3;
				if(v[i]%2==0) sec = v[i]/2;
				thi = v[i]-1;
				if(first != -1 and s.find(first) == s.end()) {
					v.push_back(first);
					s.insert(first);
				}
				if(sec != -1 and s.find(sec) == s.end()) {
					v.push_back(sec);
					s.insert(sec);
				}
				if(s.find(thi) == s.end()) {
					v.push_back(thi);
					s.insert(thi);
				}
				if(first == 1 || sec == 1 || thi == 1) {
					found = 1;
				}
			}
			i = cs;
			cs = v.size();
		}
		cout<<ans<<endl;
	}
}