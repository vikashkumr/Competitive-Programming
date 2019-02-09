#include<bits/stdc++.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		long long n;
		long long sum=0;
		cin>>n;
		long long arr[n];
		for(long long i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		//sort(arr,arr+n);
		cout<<(sum-n+1)<<endl;
	}
	return 0;
}
