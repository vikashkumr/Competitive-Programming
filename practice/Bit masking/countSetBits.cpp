//count no of set bits in a number
//O(no. of bits)
//©vikash
#include<iostream>
using namespace std;
int setBits(int n){
	int cnt=0;
	while(n>0){
		n=n&(n-1);
		cnt++;
	}
	return cnt;
}
int main(){
	int n,temp,cnt=0;
	cout<<"enter a number:\n";
	cin>>n;
	temp=n;
	while(temp>0){
		cnt+=(temp&1);
		temp=temp>>1;
	}
	cout<<cnt<<" Order(no of bits:)"<<endl;
	//O(no. of set bits)
	cout<<setBits(n)<<" Order(no of set bits:)"<<endl;
	return 0;
}
