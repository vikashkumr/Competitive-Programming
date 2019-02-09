#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int A[n],D[n],temp[n];
		for(int i=0;i<n;i++)
		cin>>A[i];
		for(int i=0;i<n;i++)
		cin>>D[i];
		temp[0]=A[1]+A[n-1];
		temp[n-1]=A[n-2]+A[0];
		for(int i=1;i<n-1;i++){
			temp[i]=A[i-1]+A[i+1];
		}
		//vector<touple<int,int,int> >v;
		int ans=-1;
		for(int i=0;i<n;i++){
			if((D[i]-temp[i])>0 && D[i]>ans){
				ans=D[i];
			}
		//	ans=D[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
