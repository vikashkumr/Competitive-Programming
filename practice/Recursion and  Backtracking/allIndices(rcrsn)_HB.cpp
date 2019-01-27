#include<iostream>
using namespace std;
void printIndices(int arr[],int size,int x,int limit){
	if(size==limit)
	return ;
	if(arr[size]==x)
	cout<<size<<" ";
	return printIndices(arr,size+1,x,limit);
}
int main(){
	int n,m;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>m;
	printIndices(arr,0,m,n);
	return 0;
}
