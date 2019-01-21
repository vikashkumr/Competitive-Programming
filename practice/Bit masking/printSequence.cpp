//subsequence of string ...bitmasking
//©vikash
#include<iostream>
#include<cstring>
using namespace std;
void printSequence(char *a,int length){
	int i=0;
	while(length>0){
		if(length&1)
		cout<<a[i];
		length=length>>1;
		i++;
	}
	cout<<" ";
}
int main(){
	char arr[]={'a','b','c'};
	int n=strlen(arr);
	for(int i=1;i<=(1<<n)-1;i++)
	printSequence(arr,i);
	return 0;
}
