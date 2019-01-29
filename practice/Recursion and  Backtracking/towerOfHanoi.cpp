//tower of hanoi
//©vikash
#include<iostream>
using namespace std;
void tower(int n,char from,char to ,char via,int top){
	if(n==1){
		cout<<"Moving ring "<<top<<" from "<<from<<" to "<<to<<endl;
		return ;}
	else {
		tower(n-1,from,via,to,top);
		top=n; 
		tower(1,from,to,via,top);
		top=1;
		tower(n-1,via,to,from,top);
	}
}
int main(){
	int n;
	cin>>n;
	tower(n,'A','B','C',1);
	return 0;
}
