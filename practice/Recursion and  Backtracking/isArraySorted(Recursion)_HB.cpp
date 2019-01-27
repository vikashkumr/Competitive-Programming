#include<iostream>
using namespace std;
bool isSorted(int arr[],int size){
	if(size==0 || size==1)
	return true;
	if(arr[size]>=arr[size-1])
	return isSorted(arr,size-1);
	else
	return false;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	bool temp=isSorted(arr,n-1);
	if(temp)
	cout<<"true"<<endl;
	else
	cout<<"false";
	return 0;
}
