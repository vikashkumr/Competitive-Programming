#include<iostream>
using namespace std;
int indexFinder(int arr[],int size,int x){
	if(size==-1)
	return -1;
	if(arr[size]==x)
	return size;
	else
	return indexFinder(arr,size-1,x);
}
int main(){
	int n,m,ans;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cin>>m;
	ans=indexFinder(arr,n-1,m);
	if(ans!=-1)
	cout<<ans<<endl;
	else
	cout<<"-1"<<endl;
	return 0;
}
