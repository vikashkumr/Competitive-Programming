//Mattrix exponentiation for fibbonacci number
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
ll k=2;

vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B){
	vector<vector<ll> > C(k,vector<ll>(k));

	for(ll i=0;i<k;i++){
		for(ll j=0;j<k;j++){
			for(ll x=0;x<k;x++){
				C[i][j] = (C[i][j]+(A[i][x]*B[x][j])%MOD)%MOD;
			}
		}
	}
	return C;
}

vector<vector<ll> > pow(vector<vector<ll> > A, ll n){
	if(n==1) return A;
	if(n&1){
		return multiply(A,pow(A,n-1));
	}
	else {
		vector<vector<ll> > x = pow(A,n/2);
		return multiply(x,x);
	}

}

int main () {
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<vector<ll> > t(k,vector<ll>(k));
		t[0][0]=0;
		t[0][1] = 1;
		t[1][0] = 1;
		t[1][1] = 1;
		t = pow(t,n-1);
		ll ans;
		ans = t[0][0]+t[0][1];
		cout<<ans<<endl; 
	}

	return 0;
}
