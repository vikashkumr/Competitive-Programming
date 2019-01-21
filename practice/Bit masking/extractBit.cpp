//extract ith bit ..bitmasking
//©vikash
#include<iostream>
using namespace std;
int main(){
	int x,bit,mask;
	cout<<"enter a number: \n";
	cin>>x;
	cout<<"enter bit number you want to extract from left:\n";
	cin>>bit;
	mask=(1<<bit);
	cout<<(x&mask? 1 : 0);
	return 0;
}
