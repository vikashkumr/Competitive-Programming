//©vikash
#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false)
#define ll long long int
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
int main(){
	fio;
	ll n;
	cin>>n;
	while(n){
        ll temp=1,arr[n],ans=n;
        F(i,0,n-1)
        cin>>arr[i];
        stack<ll>st;
        ll i=0;
        while(i!=n){
        	if(arr[i]==temp){
        		i++;
        		temp++;
        		ans--;
			}
			else if(st.empty()!=1 && st.top()==temp){
				st.pop();
				temp++;
				ans--;
			}
			else if(st.empty() || st.top()>=arr[i]){
				st.push(arr[i]);
				i++;
			}
			else
			break;
		}
		while(st.empty()!=1){
			if(st.top()==temp){
				temp++;
				ans--;
				st.pop();
			}
			else
			break;
		}
		if(ans==0)
	    cout<<"yes\n";
		else
		cout<<"no\n";
		cin>>n;
	}
	return 0;
}
