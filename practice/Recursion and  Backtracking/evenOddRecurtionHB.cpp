#include<bits/stdc++.h>
using namespace std;
void oddEven(int n){
	if(n==1){
		cout<<n<<endl;
		return ;
	}
	if(n%2!=0){
		cout<<n<<endl;
	}
	oddEven(n-1);
	if((n&1)==0)
	cout<<n<<endl;
}
int main(){
	int n;
	cin>>n;
	oddEven(n);
	return 0;
}
