//count number of set bits in all number from a to b 
//©vikash
//hacker blocks
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans=arr[0];
	for(int i=1;i<n;i++){
		ans^=arr[i];
	}
	int cnt=0,temp,t=ans,t1=ans;
	//finding which bit is 1
	while(t>0){
		if(t&1){
			break;
		}
		t=t>>1;
		cnt++;
	}
	temp=(1<<cnt);
	for(int i=0;i<n;i++){
		if((temp&arr[i])!=0)
		t1^=arr[i];
	}
	cout<<t1<<" "<<(t1^ans);
	return 0;
}
