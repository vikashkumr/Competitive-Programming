//xor swapping bitmasking
//©vikash
#include<iostream>
using namespace std;
int main(){
	int x,y;
	cout<<"enter x & y:\n";
	cin>>x>>y;
	x=x^y;
	y=y^x;
	x=x^y;
	cout<<"after xor swapping :x : "<<x<<" y : "<<y;
	
	return 0;
}
