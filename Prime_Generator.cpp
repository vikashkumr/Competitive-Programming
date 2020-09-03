#include<bits/stdc++.h>
using namespace std;
void simpleSieve(long long n,vector<int> &prime) {
	bool isPrime[n+1];
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0]=false;
	isPrime[1]=false;
	for(int i=2;i*i<=n;i++) {
		for(int j=2*i;j<=n;j+=i)
		isPrime[j]=false;
	}
	for(int i=2;i<=n;i++) {
        if(isPrime[i]==true)
        prime.push_back(i);
    }
}
void segmentedSieve(long long a,long long b) {
	long long temp=floor(sqrt(b));
	bool isPrime[b-a+1];
	vector<int>prime;
	simpleSieve(temp,prime);
	memset(isPrime,true,sizeof(isPrime));
	for(int i=0;i<prime.size();i++) {
		int  curr_prime=prime[i];
		long long base=(a/prime[i])*prime[i];
		if(base<a)
		base+=curr_prime;
		for(long long j=base;j<=b;j+=curr_prime) {
			isPrime[j-a]=false;
		}
		if(base==curr_prime) {
			isPrime[base-a]=true;
		}	
	}
	if(a==1)
	for(long long k=1;k<b-a+1;k++) {
		if(isPrime[k]==true)
		cout<<k+a<<"\n";
	}
	else for(long long k=0;k<b-a+1;k++) {
		if(isPrime[k]==true)
		cout<<k+a<<"\n";
	}
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		segmentedSieve(a,b);
		printf("\n");
	}
	return 0;
}