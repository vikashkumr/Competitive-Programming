//based on binary search
//©vikash
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,s=0,temp;
	cin>>n;
	int space[n],sum[n];
	for(int i=0;i<n;i++){
		cin>>space[i];
	}
	sort(space,space+n);
	for(int i=0;i<n;i++){
		s+=space[i];
		sum[i]=s;
	}
	int q,x,mid,ans;
	cin>>q;
	while(q--){
		int l=0,r=n-1;
		cin>>x;
		while(l<=r){
			mid=(l+r)/2;
			if(space[mid]<=x){
				ans=mid;
				l=mid+1;
			}
			else
			r=mid-1;
		}
		cout<<ans+1<<" "<<sum[ans]<<endl;
	}
}
