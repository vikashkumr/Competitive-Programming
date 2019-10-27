#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll d[100010],t[100010],s[100010];
vector<ll>date[100010];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		ll n,D,ans=0;
		cin>>n>>D;
		for(int i = 0; i <= D; ++i) date[i].clear();
		for(ll i=1;i<=n;i++){
			cin>>d[i]>>t[i]>>s[i];
			date[d[i]].push_back(i);
			ans+=t[i]*s[i];
		}

		priority_queue<pair<ll,ll> >pq;

		for(ll day=1;day<=D;day++){
			for(auto x : date[day]){
				pq.push({s[x],x});
			}

			if(pq.empty()) continue;
			auto temp = pq.top();
			t[temp.second]--;
            ans-=temp.first;
			if(t[temp.second]==0){
				pq.pop();
			}	
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}